#pragma once
#include "Day.h"

class Month
{
private:
    char* name;
    int numberOfDays;
    vector<Day> days;

    void copy(const Month& other);
    void erase();
public:
    Month();
    Month(const Month& other);
    Month& operator=(const Month& other);
    ~Month();
    void setName(const char* _name);
    void setNumberOfDays(int number);
    int getNumberOfDays()const;
    char* getName()const;
    vector<Day> getDays()const;
    void print(int c, int p)const;
    void addTask(Task* t, int d);
    void removeTask(const Task& _task);
    void write(ofstream& out);
    void read(ifstream& in);
    //from here on , it's all for the print xD..
    void setJan();
    void setFeb1();
    void setFeb2();
    void setMarch1();
    void setMarch2();
    void setApr1();
    void setApr2();
    void setMay1();
    void setMay2();
    void setJune1();
    void setJune2();
    void setJuly1();
    void setJuly2();
    void setAug1();
    void setAug2();
    void setSep1();
    void setSep2();
    void setOct1();
    void setOct2();
    void setNov1();
    void setNov2();
    void setDec1();
    void setDec2();
};
