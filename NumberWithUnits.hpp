
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
            // static void update_map(const std::string &src_unit, const std::string &dest_unit);
            static void update_map(const string &src_unit, const string &dest_unit);

        public:
            NumberWithUnits(double s,const string& u);
            static void read_units(ifstream& units_file);
            
            
            friend int compare(const NumberWithUnits& number1, const NumberWithUnits& number2);
            //operator:input,output
            friend std::ostream& operator<< (std::ostream& output, const NumberWithUnits& number);
            friend std::istream& operator>> (std::istream& input , NumberWithUnits& number);

            friend NumberWithUnits operator+(const NumberWithUnits& number1,const NumberWithUnits& number2);
            friend NumberWithUnits operator+(const NumberWithUnits& number, double num);
            friend const NumberWithUnits& operator+(const NumberWithUnits& number1);
            friend NumberWithUnits operator-(const NumberWithUnits& number1,const NumberWithUnits& number2);
            friend NumberWithUnits operator-(const NumberWithUnits& number, double num);
            friend NumberWithUnits operator-(const NumberWithUnits& number);
            // friend NumberWithUnits operator+=(const NumberWithUnits& number1,const NumberWithUnits& number2);
            NumberWithUnits& operator+=(const NumberWithUnits& number);
            
            // friend NumberWithUnits operator-=(const NumberWithUnits& number1,const NumberWithUnits& number2);
            NumberWithUnits& operator-=(const NumberWithUnits& number);
            friend NumberWithUnits& operator++(NumberWithUnits& number);
            friend NumberWithUnits operator++(NumberWithUnits& number,int num);
            friend NumberWithUnits& operator--(NumberWithUnits& number);
            friend NumberWithUnits operator--(NumberWithUnits& number,int num);
            friend NumberWithUnits operator*(const NumberWithUnits &number,const double &num);
            friend NumberWithUnits operator*(const double &num,const NumberWithUnits &number);
            friend bool operator>(const NumberWithUnits &number1,const NumberWithUnits &number2);
            friend bool operator>=(const NumberWithUnits &number1,const NumberWithUnits &number2);
            friend bool operator<(const NumberWithUnits &number1,const NumberWithUnits &number2);
            friend bool operator<=(const NumberWithUnits &number1,const NumberWithUnits &number2);
            friend bool operator==(const NumberWithUnits &number1,const NumberWithUnits &number2);
            friend bool operator!=(const NumberWithUnits &number1,const NumberWithUnits &number2);

        // //operator: +,=,+=,-,-=
            // friend NumberWithUnits operator+(const NumberWithUnits& number1, const NumberWithUnits& number2);
            // friend NumberWithUnits operator+(const NumberWithUnits& number, double a);
            // NumberWithUnits operator+() const;
            // friend NumberWithUnits operator-(const NumberWithUnits& number1, const NumberWithUnits& number2);
            // friend NumberWithUnits operator-(const NumberWithUnits& number ,double a);
            // NumberWithUnits operator-() const;
            // friend NumberWithUnits operator+=(const NumberWithUnits& number1,const NumberWithUnits& number2);
            // friend NumberWithUnits operator-=(const NumberWithUnits& number1,const NumberWithUnits& number2);
                        
            // //operator: ==,!=,<=,>=
            // friend bool operator<=(const NumberWithUnits& number1, const NumberWithUnits& number2);
            // friend bool operator==(const NumberWithUnits& number1, const NumberWithUnits& number2);
            // friend bool operator!=(const NumberWithUnits& number1, const NumberWithUnits& number2);
            // friend bool operator>=(const NumberWithUnits& number1, const NumberWithUnits& number2);
            // friend bool operator<(const NumberWithUnits& number1, const NumberWithUnits& number2);
            // friend bool operator>(const NumberWithUnits& number1, const NumberWithUnits& number2);
            // //operator: * ,*=
            // friend NumberWithUnits operator*(double number1,  NumberWithUnits& number2);
            // friend NumberWithUnits operator*=(  NumberWithUnits& number2, double number1);
            // friend NumberWithUnits operator*(  NumberWithUnits& number2,double number1);
            // friend NumberWithUnits operator*=( double number1,NumberWithUnits  &number2);     
            // //operator: ++,--
            // friend NumberWithUnits operator++( NumberWithUnits& number1);     
            // friend NumberWithUnits operator--( NumberWithUnits& number1);     
            // friend NumberWithUnits operator++( NumberWithUnits& number1, int a);          
            // friend NumberWithUnits operator--( NumberWithUnits& number1, int a);     
        

    };    
    
}