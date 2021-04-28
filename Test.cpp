// #include "NumberWithUnits.hpp"
// #include "doctest.h"
// #include <iostream>
#include "doctest.h"
#include "NumberWithUnits.hpp"
#include <iostream>
#include <ctime>
#include <stdexcept>
#include <string>
using namespace ariel;
using namespace std;

NumberWithUnits km(3, "km");
NumberWithUnits cm(3, "cm");
NumberWithUnits hour(3, "hour");
NumberWithUnits sec(3, "sec");
NumberWithUnits ton(3, "ton");
NumberWithUnits kg(3, "kg");
NumberWithUnits USD(3, "USD");

TEST_CASE("+,-")
{
    km = km + cm;
    CHECK(km == NumberWithUnits(3.003, "km"));
    km = km - cm;
    CHECK(km == NumberWithUnits(3, "km"));
    hour = hour + sec;
    CHECK(hour == NumberWithUnits(3.003, "hour"));
    hour = hour - sec;
    CHECK(hour == NumberWithUnits(3, "hour"));
    ton = ton + kg;
    CHECK(ton == NumberWithUnits(3.003, "ton"));
    ton = ton - kg;
    CHECK(ton == NumberWithUnits(3, "ton"));
}

TEST_CASE("+=")
{
    km += cm;
    CHECK(km == NumberWithUnits(3.003, "km"));
    km -= cm;
    CHECK(km == NumberWithUnits(3, "km"));
    hour += sec;
    CHECK(hour == NumberWithUnits(3.003, "hour"));
    hour -= sec;
    CHECK(hour == NumberWithUnits(3, "hour"));
    ton += kg;
    CHECK(ton == NumberWithUnits(3.003, "ton"));
    ton -= kg;
    CHECK(km == NumberWithUnits(3, "km"));
}

TEST_CASE(">, >=, <, <=, ==, !=")
{
    CHECK_GT(km, cm);
    CHECK_LT(cm, km);
    CHECK_GT(hour, sec);
    CHECK_LT(sec, hour);
    CHECK_GT(ton, kg);
    CHECK_LT(kg, ton);

    CHECK_GE(km, km);
    CHECK_LE(km, km);
    CHECK_EQ(km, NumberWithUnits(3000, "m"));
}

TEST_CASE("++,--")
{
    km++;
    CHECK(km == NumberWithUnits(4, "km"));
    km--;
    CHECK(km == NumberWithUnits(3, "km"));
    hour++;
    CHECK(hour == NumberWithUnits(4, "hour"));
    hour--;
    CHECK(hour == NumberWithUnits(3, "hour"));
    ton++;
    CHECK(ton == NumberWithUnits(4, "ton"));
    ton--;
    CHECK(ton == NumberWithUnits(3, "ton"));
}
TEST_CASE("*")
{
    km = km * 2;
    CHECK(km == NumberWithUnits(6, "km"));
    hour = hour * 2;
    CHECK(hour == NumberWithUnits(6, "hour"));
    ton = ton * 2;
    CHECK(ton == NumberWithUnits(6, "ton"));
}