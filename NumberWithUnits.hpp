
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;
namespace ariel{
        class NumberWithUnits{
        
        private:
            double size;
            string unit;
            double adjust_unit(const NumberWithUnits &unit1) const;
            static void update_map(const string &src_unit, const string &dest_unit);

        public:
            //builder
            NumberWithUnits(double s,const string& u);
            //reading units from file
            static void read_units(ifstream& units_file);
            
            
            //operator:input,output
            friend std::ostream& operator<< (std::ostream& output, const NumberWithUnits& number);
            friend std::istream& operator>> (std::istream& input , NumberWithUnits& number);

            //+,-,+=,-=
            friend NumberWithUnits operator+(const NumberWithUnits& number1,const NumberWithUnits& number2);
            friend NumberWithUnits operator+(const NumberWithUnits& number, double num);
            friend const NumberWithUnits& operator+(const NumberWithUnits& number1);
            friend NumberWithUnits operator-(const NumberWithUnits& number1,const NumberWithUnits& number2);
            friend NumberWithUnits operator-(const NumberWithUnits& number, double num);
            friend NumberWithUnits operator-(const NumberWithUnits& number);
            NumberWithUnits& operator+=(const NumberWithUnits& number);
            NumberWithUnits& operator-=(const NumberWithUnits& number);

            //++,--,*
            friend NumberWithUnits& operator++(NumberWithUnits& number);
            friend NumberWithUnits operator++(NumberWithUnits& number,int num);
            friend NumberWithUnits& operator--(NumberWithUnits& number);
            friend NumberWithUnits operator--(NumberWithUnits& number,int num);
            friend NumberWithUnits operator*(const NumberWithUnits &number,const double &num);
            friend NumberWithUnits operator*(const double &num,const NumberWithUnits &number);

            //compare , >,>=,<,<=,==,!=
            friend int compare(const NumberWithUnits& number1, const NumberWithUnits& number2);
            friend bool operator>(const NumberWithUnits &number1,const NumberWithUnits &number2);
            friend bool operator>=(const NumberWithUnits &number1,const NumberWithUnits &number2);
            friend bool operator<(const NumberWithUnits &number1,const NumberWithUnits &number2);
            friend bool operator<=(const NumberWithUnits &number1,const NumberWithUnits &number2);
            friend bool operator==(const NumberWithUnits &number1,const NumberWithUnits &number2);
            friend bool operator!=(const NumberWithUnits &number1,const NumberWithUnits &number2);

    };    
    
}