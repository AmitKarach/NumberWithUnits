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
namespace ariel{
            std::map<string,std::map<string,double>> units;

             void  NumberWithUnits::read_units(ifstream& file)
             {
                string buff, unitA, unitB;
                double size1=0, size2=0;
                while(file >> size1 >> unitA >> buff >> size2 >> unitB)
                {                
                    units[unitA][unitB] = size2;
                    units[unitB][unitA] = 1/size2;
                     update_map(unitA, unitB);
                     update_map(unitB, unitA);                  
                }
             }

            void NumberWithUnits::update_map(const string &src_unit, const string &dest_unit){
                for(auto &unit : units[dest_unit]){
                    if(unit.first != src_unit){
                        double new_size = units[src_unit][dest_unit]*unit.second;
                        units[src_unit][unit.first] = new_size;
                        units[unit.first][src_unit] = 1/new_size;
                    }
                }
            }

             NumberWithUnits::NumberWithUnits(double s,const string& u)
            {
                if(units.find(u) == units.end()){
                    throw invalid_argument(u + " invalid unit");
                 }   
                this->size=s;
                this->unit=u;
            }

        double NumberWithUnits::adjust_unit(const NumberWithUnits &unit1) const{
            if(!(unit == unit1.unit || units[unit].find(unit1.unit) != units[unit].end())){
                throw invalid_argument("diffrent family");
            }
            if(unit == unit1.unit)
            {
                return unit1.size;
            }
            return unit1.size*units[unit1.unit][unit];
    }

            //operator: +,=,+=,-,-=
             NumberWithUnits operator+(const NumberWithUnits& number1, const NumberWithUnits& number2){
                 return NumberWithUnits(number1.size + number1.adjust_unit(number2),number1.unit);
            }
    	    
            NumberWithUnits operator+(const NumberWithUnits& number, double num){
                 return NumberWithUnits(number.size+num, number.unit);
            }
            const NumberWithUnits& operator+(const NumberWithUnits &number){
                 return number;
            }

            NumberWithUnits operator-(const NumberWithUnits& number1, const NumberWithUnits& number2){
                 return NumberWithUnits(number1.size - number1.adjust_unit(number2),number1.unit);
             }
             
            
             NumberWithUnits operator-(const NumberWithUnits& number, double num){
                 return NumberWithUnits(number.size-num, number.unit);
             }

            NumberWithUnits operator-(const NumberWithUnits& number){
               return NumberWithUnits(-number.size, number.unit);
            } 

            //  NumberWithUnits operator+=(const NumberWithUnits& number1,const NumberWithUnits& number2){
            //      return number1+number2;
            //  }
            NumberWithUnits& NumberWithUnits::operator+=(const NumberWithUnits& number){
                double num2_val=this->adjust_unit(number);
                this->size+=num2_val;
                return *this;
            }
            //  NumberWithUnits operator-=(const NumberWithUnits& number1, const NumberWithUnits& number2){
            //      return number1-number2;
            //  }
            NumberWithUnits& NumberWithUnits::operator-=(const NumberWithUnits& number){
                double num2_val=this->adjust_unit(number);
                this->size-=num2_val;
                return *this;
            }
            //operator: ==,!=,<=,>=
           
            bool operator==(const NumberWithUnits& number1, const NumberWithUnits& number2){
                return (fabs(number1.size - number1.adjust_unit(number2)) <= EPS);
             }

            bool operator!=(const NumberWithUnits& number1, const NumberWithUnits& number2){
                return number1.size != number1.adjust_unit(number2);
             }
            bool operator>=(const NumberWithUnits& number1, const NumberWithUnits& number2){
                return compare(number1, number2) >= 0;
             }
             bool operator<(const NumberWithUnits& number1, const NumberWithUnits& number2){
                return compare(number1, number2) < 0;
             }
             bool operator>(const NumberWithUnits& number1, const NumberWithUnits& number2){
                return compare(number1, number2) > 0;
             }
               bool operator<=(const NumberWithUnits& number1, const NumberWithUnits& number2){
                return compare(number1, number2) <= 0;
             }
            //operator: * ,*=
             NumberWithUnits operator*( const NumberWithUnits &number,const double &num){
                return NumberWithUnits(number.size*num, number.unit);
             }
            //  NumberWithUnits operator*=( NumberWithUnits& number, double num){
            //     return NumberWithUnits(number.size*num, number.unit);
            //  }
             NumberWithUnits operator*(const double &num,const NumberWithUnits &number){
                return NumberWithUnits(number.size*num, number.unit);
             }
            //  NumberWithUnits operator*=( double num,NumberWithUnits& number){
            //     return NumberWithUnits(number.size*num, number.unit);
            //  }    
            //operator: ++,--
             NumberWithUnits& operator++( NumberWithUnits& number){
               number.size++;
               return number;
             }     
             NumberWithUnits& operator--( NumberWithUnits& number){
               number.size--;
               return number; 
             }    
             NumberWithUnits operator++( NumberWithUnits& number, int num){
                NumberWithUnits befor(number.size, number.unit);
                number.size++;
                return befor;
             }         
             NumberWithUnits operator--( NumberWithUnits& number, int num)
             {
                NumberWithUnits befor(number.size, number.unit);
                number.size--;
                return befor;
             }    
        
            //  int compare(const NumberWithUnits& number1, const NumberWithUnits& number2)
            //  {
            //     double check = fabs(number1.size - number1.adjust_unit(number2));
            //     if(check<EPS)
            //     {
            //         return 0;
            //     }
                    
            //     if(check>0)
            //     {
            //         return 1;
            //     }
            //     return -1;
            //  }
            int compare(const NumberWithUnits &n1, const NumberWithUnits &n2) {
        
                NumberWithUnits n2_con(n1.adjust_unit(n2), n1.unit);
                double check= (n1.size - n2_con.size);
                double ab=fabs(check);
                int ans=0;
                if (ab<EPS){
                    ans=0;
                }
                else if(check>0) {
                        ans= 1;
                    }
                    else{
                        ans=-1;
                    }
        
                return ans;
            }
            //operator:input,output
             std::ostream& operator<< (std::ostream& output, const NumberWithUnits& number){
                output << number.size << "[" << number.unit << ']';
                return output;
             }
            istream &operator>>(istream &s, NumberWithUnits &n)
            {
                char c = 0;
                string t;
                double v = 0;
                s >> v >> c >> t >> c;
                if (t[t.length() - 1] == ']')
                {
                    t.pop_back();
                }
                if (c == '-')
                {
                    s.putback('-');
                }
                try
                {
                    units.at(t);
                    n.size = v;
                    n.unit = t;
                    return s;
                }
                catch (const exception &e)
                {
                    throw std::invalid_argument(t + " is not a valid unit!");
                }
            }


}