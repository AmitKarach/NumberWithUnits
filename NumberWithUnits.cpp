#include <map>
#include "NumberWithUnits.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <math.h>
#include <string>
#include <utility>
#include <algorithm>
#include <exception>

const double EPS = 0.0001;
using namespace std;
namespace ariel
{
    std::map<string, std::map<string, double>> units;

    void NumberWithUnits::read_units(ifstream &file)
    {
        string buff, unitA, unitB;
        double size1 = 0, size2 = 0;
        while (file >> size1 >> unitA >> buff >> size2 >> unitB)
        {
            units[unitA][unitB] = size2;
            units[unitB][unitA] = 1 / size2;
            update_map(unitA, unitB);
            update_map(unitB, unitA);
        }
    }

    void NumberWithUnits::update_map(const string &src, const string &dest)
    {
        for (auto &unit : units[dest])
        {
            if (unit.first != src)
            {
                double new_size = units[src][dest] * unit.second;
                units[src][unit.first] = new_size;
                units[unit.first][src] = 1 / new_size;
            }
        }
    }

    NumberWithUnits::NumberWithUnits(double s, const string &u)
    {
        if (units.find(u) == units.end())
        {
            throw invalid_argument(u + " invalid unit");
        }
        this->size = s;
        this->unit = u;
    }

    double NumberWithUnits::adjust_unit(const NumberWithUnits &unit1) const
    {
        if (!(unit == unit1.unit || units[unit].find(unit1.unit) != units[unit].end()))
        {
            throw invalid_argument("diffrent family");
        }
        if (unit == unit1.unit)
        {
            return unit1.size;
        }
        return unit1.size * units[unit1.unit][unit];
    }

    //operator: +,+=,-,-=
    NumberWithUnits operator+(const NumberWithUnits &number1, const NumberWithUnits &number2)
    {
        return NumberWithUnits(number1.size + number1.adjust_unit(number2), number1.unit);
    }

    NumberWithUnits operator+(const NumberWithUnits &number, double num)
    {
        return NumberWithUnits(number.size + num, number.unit);
    }
    const NumberWithUnits &operator+(const NumberWithUnits &number)
    {
        return number;
    }

    NumberWithUnits operator-(const NumberWithUnits &number1, const NumberWithUnits &number2)
    {
        return NumberWithUnits(number1.size - number1.adjust_unit(number2), number1.unit);
    }

    NumberWithUnits operator-(const NumberWithUnits &number, double num)
    {
        return NumberWithUnits(number.size - num, number.unit);
    }

    NumberWithUnits operator-(const NumberWithUnits &number)
    {
        return NumberWithUnits(-number.size, number.unit);
    }

    NumberWithUnits &NumberWithUnits::operator+=(const NumberWithUnits &number)
    {
        this->size += this->adjust_unit(number);
        return *this;
    }

    NumberWithUnits &NumberWithUnits::operator-=(const NumberWithUnits &number)
    {
        this->size -= this->adjust_unit(number);
        return *this;
    }

    //operator: ++,--,*
    NumberWithUnits &operator++(NumberWithUnits &number)
    {
        number.size++;
        return number;
    }
    NumberWithUnits &operator--(NumberWithUnits &number)
    {
        number.size--;
        return number;
    }
    NumberWithUnits operator++(NumberWithUnits &number, int num)
    {
        NumberWithUnits befor(number.size, number.unit);
        number.size++;
        return befor;
    }
    NumberWithUnits operator--(NumberWithUnits &number, int num)
    {
        NumberWithUnits befor(number.size, number.unit);
        number.size--;
        return befor;
    }
    NumberWithUnits operator*(const NumberWithUnits &number, const double &num)
    {
        return NumberWithUnits(number.size * num, number.unit);
    }

    NumberWithUnits operator*(const double &num, const NumberWithUnits &number)
    {
        return NumberWithUnits(number.size * num, number.unit);
    }

    //compare , >,>=,<,<=,==,!=
    int compare(const NumberWithUnits &number1, const NumberWithUnits &number2)
    {
        double check = (number1.size - number1.adjust_unit(number2));
        double check_positive = fabs(check);
        if (check_positive < EPS)
        {
            return 0;
        }
        else if (check > 0)
        {
            return 1;
        }
        else
        {
            return -1;
        }

    }

    bool operator==(const NumberWithUnits &number1, const NumberWithUnits &number2)
    {
        return (fabs(number1.size - number1.adjust_unit(number2)) <= EPS);
    }

    bool operator!=(const NumberWithUnits &number1, const NumberWithUnits &number2)
    {
        return number1.size != number1.adjust_unit(number2);
    }
    bool operator>=(const NumberWithUnits &number1, const NumberWithUnits &number2)
    {
        return compare(number1, number2) >= 0;
    }
    bool operator<(const NumberWithUnits &number1, const NumberWithUnits &number2)
    {
        return compare(number1, number2) < 0;
    }
    bool operator>(const NumberWithUnits &number1, const NumberWithUnits &number2)
    {
        return compare(number1, number2) > 0;
    }
    bool operator<=(const NumberWithUnits &number1, const NumberWithUnits &number2)
    {
        return compare(number1, number2) <= 0;
    }
    //operator:input,output
    std::ostream &operator<<(std::ostream &output, const NumberWithUnits &number)
    {
        output << number.size << "[" << number.unit << ']';
        return output;
    }

    istream &operator>>(istream &input, NumberWithUnits &number)
    {
        char cha = 0;
        string unit;
        double size = 0;
        input >> size >> cha >> unit >> cha;

        if (unit[unit.length() - 1] == ']')
        {
            unit.pop_back();
        }
        if (cha == '-')
        {
            input.putback('-');
        }
        if (units.find(unit) == units.end())
        {
            throw std::invalid_argument(unit + " is not a valid unit!");
        }
        number.size = size;
        number.unit = unit;
        return input;
    }

}