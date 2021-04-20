
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
        
        
        public:
            NumberWithUnits(double s,string u)
            {
                size=s;
                unit=u;
            }

            static void read_units(ifstream& units_file);

            //operator: +,=,+=,-,-=
            friend NumberWithUnits& operator+(const NumberWithUnits& number1, const NumberWithUnits& number2);
            friend NumberWithUnits& operator-(const NumberWithUnits& number1, const NumberWithUnits& number2);
            friend NumberWithUnits& operator+=(NumberWithUnits& number1, const NumberWithUnits& number2);
            friend NumberWithUnits& operator-=(NumberWithUnits& number1, const NumberWithUnits& number2);
            friend NumberWithUnits& operator+(const NumberWithUnits& number1);
            friend NumberWithUnits& operator-(const NumberWithUnits& number1);
            //operator: ==,!=,<=,>=
            friend bool operator<=(const NumberWithUnits& number1, const NumberWithUnits& number2);
            friend bool operator==(const NumberWithUnits& number1, const NumberWithUnits& number2);
            friend bool operator!=(const NumberWithUnits& number1, const NumberWithUnits& number2);
            friend bool operator>=(const NumberWithUnits& number1, const NumberWithUnits& number2);
            friend bool operator<(const NumberWithUnits& number1, const NumberWithUnits& number2);
            friend bool operator>(const NumberWithUnits& number1, const NumberWithUnits& number2);
            //operator: * ,*=
            friend NumberWithUnits& operator*(double number1,  NumberWithUnits& number2);
            friend NumberWithUnits& operator*=(  NumberWithUnits& number2, double number1);
            friend NumberWithUnits& operator*(  NumberWithUnits& number2,double number1);
            friend NumberWithUnits& operator*=( double number1,NumberWithUnits  &number2);     
            //operator: ++,--
            friend NumberWithUnits& operator++( NumberWithUnits& number1);     
            friend NumberWithUnits& operator--( NumberWithUnits& number1);     
            friend NumberWithUnits& operator++( NumberWithUnits& number1, int);          
            friend NumberWithUnits& operator--( NumberWithUnits& number1, int);     
        
            friend int comp(const NumberWithUnits& number1, const NumberWithUnits& number2);
            //operator:input,output
            friend std::ostream& operator<< (std::ostream& output, const NumberWithUnits& c);
            friend std::istream& operator>> (std::istream& input , NumberWithUnits& c);


    };    
    
}