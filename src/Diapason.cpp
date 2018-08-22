#include "Diapason.h"

Diapason::Diapason()
{
    this->start.setHour(0);
    this->start.setMinutes(0);
    this->start.setSeconds(0);
    this->end.setHour(0);
    this->end.setMinutes(0);
    this->end.setSeconds(0);
}

Diapason::Diapason(Time s, Time e)
{
    this->start = s;
    this->end = e;
}

void Diapason::setStart(Time s){this->start = s;}

void Diapason::setEnd(Time e){this->end = e;}

Time Diapason::getStart()const{return this->start;}

Time Diapason::getEnd()const{return this->end;}

Time Diapason::getPeriod()const
{
    Time s = this->start;
    Time e = this->end;
    return (s - e);
}

void Diapason::print()const
{
    this->start.print();
    cout << " - ";
    this->end.print();
}

bool Diapason::operator==(const Diapason other)
{
    return (this->start == other.start &&
            this->end == other.end);
}

void Diapason::write(ofstream& out)
{
    this->start.write(out);
    this->end.write(out);
}

void Diapason::read(ifstream& in)
{
    this->start.read(in);
    this->end.read(in);
}












