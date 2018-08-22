#include "Calendar.h"

void Calendar::copy(const Calendar& other)
{
    if(other.description == nullptr)
        this->description = nullptr;
    else
    {
        this->description = new char[strlen(other.description) + 1];
        strcpy(this->description, other.description);
    }
    this->year = other.year;
    for(int i = 0; i < 12; i++)
    {
        this->months[i] = other.months[i];
    }
}

void Calendar::erase()
{
    delete[] this->description;
}

Calendar::Calendar()
{
    this->description = new char[0];
    strcpy(this->description, "");
    this->year = 0;
}

Calendar::Calendar(int _year)
{
    this->setYear(_year);
    this->months[0].setJan();
    if(this->year % 4 == 0)
    {
        if(this->year % 100 == 0)
        {
            if(this->year % 400 == 0)
            {
                this->months[1].setFeb2();
                this->months[2].setMarch2();
                this->months[3].setApr2();
                this->months[4].setMay2();
                this->months[5].setJune2();
                this->months[6].setJuly2();
                this->months[7].setAug2();
                this->months[8].setSep2();
                this->months[9].setOct2();
                this->months[10].setNov2();
                this->months[11].setDec2();
            }
            else
            {
                this->months[1].setFeb1();
                this->months[2].setMarch1();
                this->months[3].setApr1();
                this->months[4].setMay1();
                this->months[5].setJune1();
                this->months[6].setJuly1();
                this->months[7].setAug1();
                this->months[8].setSep1();
                this->months[9].setOct1();
                this->months[10].setNov1();
                this->months[11].setDec1();
            }
        }
        else
        {
            this->months[1].setFeb2();
            this->months[2].setMarch2();
            this->months[3].setApr2();
            this->months[4].setMay2();
            this->months[5].setJune2();
            this->months[6].setJuly2();
            this->months[7].setAug2();
            this->months[8].setSep2();
            this->months[9].setOct2();
            this->months[10].setNov2();
            this->months[11].setDec2();
        }

    }
    else
    {
        this->months[1].setFeb1();
        this->months[2].setMarch1();
        this->months[3].setApr1();
        this->months[4].setMay1();
        this->months[5].setJune1();
        this->months[6].setJuly1();
        this->months[7].setAug1();
        this->months[8].setSep1();
        this->months[9].setOct1();
        this->months[10].setNov1();
        this->months[11].setDec1();
    }
    this->description = new char[0];
    strcpy(this->description, "");
}

Calendar::Calendar(const Calendar& other){this->copy(other);}

Calendar& Calendar::operator=(const Calendar& other)
{
    if(this != &other)
    {
        this->erase();
        this->copy(other);
    }
    return *this;
}

Calendar::~Calendar(){this->erase();}

void Calendar::setYear(int _year){this->year = _year;}

void Calendar::setDescription(const char* _description)
{
    this->description = new char[strlen(_description) + 1];
    strcpy(this->description, _description);
}

int Calendar::getYear()const{return this->year;}

char* Calendar::getDescription()const{return this->description;}

void Calendar::print()const
{
    cout << "Year: " << this->year << endl;
    cout << "Description: " << this->description << endl;
    for(int i = 0; i < 12; i++)
    {
        if(i >= 1)
        {
            vector<Day> tmp = this->months[i - 1].getDays();
            if(strcmp(tmp[tmp.size() - 1].getDayInWeek(), "Monday") == 0)
            {
                this->months[i].print(6, 6);
            }
            if(strcmp(tmp[tmp.size() - 1].getDayInWeek(), "Tuesday") == 0)
            {
                this->months[i].print(12, 5);
            }
            if(strcmp(tmp[tmp.size() - 1].getDayInWeek(), "Wednesday") == 0)
            {
                this->months[i].print(18, 4);
            }
            if(strcmp(tmp[tmp.size() - 1].getDayInWeek(), "Thursday") == 0)
            {
                this->months[i].print(24, 3);
            }
            if(strcmp(tmp[tmp.size() - 1].getDayInWeek(), "Friday") == 0)
            {
                this->months[i].print(30, 2);
            }
            if(strcmp(tmp[tmp.size() - 1].getDayInWeek(), "Saturday") == 0)
            {
                this->months[i].print(36, 1);
            }
            if(strcmp(tmp[tmp.size() - 1].getDayInWeek(), "Sunday") == 0)
            {
                this->months[i].print(0, 0);
            }
        }
        else
            this->months[i].print(0, 0);
    }
}

void Calendar::printTaskByDate(int _day, int _month)const
{
    vector<Day> tmp = this->months[_month - 1].getDays();
    tmp[_day - 1].print();
}


void Calendar::addTask(Task* _task, int _day, int _month)
{
    this->months[_month  - 1].addTask(_task, _day);
}

void Calendar::removeTask(const Task& _task)
{
    for(int i = 0; i < 12; i++)
    {
        this->months[i].removeTask(_task);
    }
}

void Calendar::write()
{
    ofstream out("calendar.txt");
    out << this->description << " ";
    out << this->year << " ";
    for(int i = 0; i < 12; i++)
    {
        this->months[i].write(out);
    }
    out.close();
}

void Calendar::read()
{
    ifstream in("calendar.txt");
    if(in.is_open() == false)
        return;
    in >> this->description;
    in >> this->year;
    for(int i = 0; i < 12; i++)
    {
        this->months[i].read(in);
    }
    in.close();
}

