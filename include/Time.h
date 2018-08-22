#pragma once
#include <iostream>
#include <cassert>
#include <cstring>
#include <fstream>

using namespace std;

class Time
{
private:
    int hour;
    int minutes;
    int seconds;
public:
    Time();
    Time(int h, int m, int s);
    void setHour(int h);
    void setMinutes(int m);
    void setSeconds(int s);
    int getHour()const;
    int getMinutes()const;
    int getSeconds()const;
    void print()const;
    Time& operator-(const Time& other);
    bool operator==(const Time other);
    void write(ofstream& out);
    void read(ifstream& in);
};
