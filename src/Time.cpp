#include "Time.h"

Time::Time()
{
    this->hour = 0;
    this->minutes = 0;
    this->seconds = 0;
}

Time::Time(int h, int m, int s)
{
    assert(h >= 0 && h < 24);
    assert(m >= 0 && m < 60);
    assert(s >= 0 && s < 60);
    this->hour = h;
    this->minutes = m;
    this->seconds = s;
}

void Time::setHour(int h)
{
    assert(h >= 0 && h < 24);
    this->hour = h;
}

void Time::setMinutes(int m)
{
    assert(m >= 0 && m < 60);
    this->minutes = m;
}

void Time::setSeconds(int s)
{
    assert(s >= 0 && s < 60);
    this->seconds = s;
}

int Time::getHour()const{return this->hour;}

int Time::getMinutes()const{return this->minutes;}

int Time::getSeconds()const{return this->seconds;}

void Time::print()const
{
    if(this->hour <= 9)
        cout << "0" << this ->hour << "::";
    else
        cout << this->hour << "::";
    if(this->minutes <= 9)
        cout << "0" << this->minutes << "::";
    else
        cout << this->minutes << "::";
    if(this->seconds <= 9)
        cout << "0" << this->seconds;
    else
        cout << this->seconds;
}

Time& Time::operator-(const Time& other)
{
    if(this->hour > other.hour)
        this->setHour(24 - (this->hour - other.hour));
    else
        this->setHour(this->hour - other.hour);
    if(this->minutes > other.minutes)
        this->setMinutes(60 - (this->minutes - other.minutes));
    else
        this->setMinutes(this->minutes - other.minutes);
    if(this->seconds > other.seconds)
        this->setSeconds(60 - (this->seconds - other.seconds));
    else
        this->setSeconds(this->seconds - other.seconds);
    return *this;
}

bool Time::operator==(const Time other)
{
    return (this->hour == other.hour &&
            this->minutes == other.minutes &&
            this->seconds == other.seconds);
}

void Time::write(ofstream& out)
{
    out << this->hour << " ";
    out << this->minutes << " ";
    out << this->seconds << " ";
}

void Time::read(ifstream& in)
{
    in >> this->hour;
    in >> this->minutes;
    in >> this->seconds;
}

