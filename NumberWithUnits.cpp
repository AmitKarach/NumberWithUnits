#include <iostream>
#include <fstream>
#include <map>
#include "NumberWithUnits.hpp"
using namespace std;
namespace ariel{
            std::map<string,std::map<string,double>> units;
            NumberWithUnits n(0,"0");
             void  NumberWithUnits::read_units(ifstream& file)
             {
                // string buff, unitA, unitB;
                // double size1, size2;
                // while(file >> size1 >> unitA >> buff >> size2 >> unitB){
                //     units[unitA][unitB] = size2;
                //     units[unitB][unitA] = 1/size2;                   
                // }

                // for(string current: units.key_comp())
                // {
                    
                // }

        
             }
            //operator: +,=,+=,-,-=
             NumberWithUnits& operator+(const NumberWithUnits& number1, const NumberWithUnits& number2){
                 return n;
                 }
             NumberWithUnits& operator-(const NumberWithUnits& number1, const NumberWithUnits& number2){
                 return n;
             }
             NumberWithUnits& operator+=(NumberWithUnits& number1, const NumberWithUnits& number2){
                 return number1;
             }
             NumberWithUnits& operator-=(NumberWithUnits& number1, const NumberWithUnits& number2){
                 return number1;
             }
             NumberWithUnits& operator+(const NumberWithUnits& number1){
                 return n;
             }
             NumberWithUnits& operator-(const NumberWithUnits& number1){
                 return n;
             }
            //operator: ==,!=,<=,>=
             bool operator<=(const NumberWithUnits& number1, const NumberWithUnits& number2){
                 return true;
             }
             bool operator==(const NumberWithUnits& number1, const NumberWithUnits& number2){
                 return true;
             }
             bool operator!=(const NumberWithUnits& number1, const NumberWithUnits& number2){
                 return true;
             }
            bool operator>=(const NumberWithUnits& number1, const NumberWithUnits& number2){
                 return true;
             }
             bool operator<(const NumberWithUnits& number1, const NumberWithUnits& number2){
                 return true;
             }
             bool operator>(const NumberWithUnits& number1, const NumberWithUnits& number2){
                 return true;
             }
            //operator: * ,*=
             NumberWithUnits& operator*( NumberWithUnits& number2 ,double number1){
                 return n;
             }
             NumberWithUnits& operator*=( NumberWithUnits& number2, double number1){
                 return n;
             }
             NumberWithUnits& operator*(double number1,  NumberWithUnits& number2){
                 return n;
             }
             NumberWithUnits& operator*=( double number1,NumberWithUnits& number2){
                 return n;
             }    
            //operator: ++,--
             NumberWithUnits& operator++( NumberWithUnits& number1){
                 return n;
             }     
             NumberWithUnits& operator--( NumberWithUnits& number1){
                 return n;
             }    
             NumberWithUnits& operator++( NumberWithUnits& number1, int){
                 return n;
             }         
             NumberWithUnits& operator--( NumberWithUnits& number1, int)
             {
                 return n;
             }    
        
             int comp(const NumberWithUnits& number1, const NumberWithUnits& number2){
                 return 0;
             }
            //operator:input,output
             std::ostream& operator<< (std::ostream& output, const NumberWithUnits& c){
                 return output;
             }
             std::istream& operator>> (std::istream& input , NumberWithUnits& c){
                 return input;
             }


}