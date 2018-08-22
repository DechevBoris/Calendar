#pragma once
#include "Time.h"

class Diapason
{
private:
    Time start;
    Time end;
public:
    Diapason();
    Diapason(Time s, Time e);
    void setStart(Time s);
    void setEnd(Time e);
    Time getStart()const;
    Time getEnd()const;
    Time getPeriod()const;
    void print()const;
    bool operator==(const Diapason other);
    void write(ofstream& out);
    void read(ifstream& in);
};
