#include "Month.h"

void Month::copy(const Month& other)
{
    if(other.name == nullptr)
        this->name = nullptr;
    else
    {
        this->name = new char[strlen(other.name) + 1];
        strcpy(this->name, other.name);
    }
    this->numberOfDays = other.numberOfDays;
    for(unsigned int i = 0; i < other.days.size(); i++)
    {
        this->days.push_back(other.days[i]);
    }
}

void Month::erase(){delete[] this->name;}

Month::Month()
{
    this->name = new char[0];
    strcpy(this->name, "");
    this->numberOfDays = 0;
}

Month::Month(const Month& other){this->copy(other);}

Month& Month::operator=(const Month& other)
{
    if(this != &other)
    {
        this->erase();
        this->copy(other);
    }
    return *this;
}

Month::~Month(){this->erase();}

void Month::setName(const char* _name)
{
    this->name = new char[strlen(_name) + 1];
    strcpy(this->name, _name);
}

void Month::setNumberOfDays(int number)
{
    assert(number >=1 && number <= 31);
    this->numberOfDays = number;
}

int Month::getNumberOfDays()const{return this->numberOfDays;}

char* Month::getName()const{return this->name;}

vector<Day> Month::getDays()const
{
    vector<Day> day;
    for(unsigned int i = 0; i < this->days.size(); i++){
        day.push_back(this->days[i]);
    }
    return day;
}

void Month::print(int c, int p)const
{
    cout << this->name << endl;
    cout << "Mon   Tue   Wed   Thu   Fri   Sat   Sun" << endl;
    for(int i = 0; i < c; i++)
            cout << " ";
    for(int i = 0; i < this->numberOfDays; i++)
    {
        if(i > 0)
        {
            if(i == p)
                cout << endl;
            //if(strcmp(this->days[i - 1].getDayInWeek(), "Sunday") == 0)
              //  cout << endl;
        }
        if(i < 9)
            cout << "0" << i + 1 << "    ";
        else
            cout << i + 1 << "    ";
        if(i == p + 6 || i == 13 + p || i == 20 + p || i == 27 + p)
            cout << endl;
    }
    cout << endl;
    cout << endl;
    for(unsigned int i = 0; i < this->days.size(); i++)
    {
        vector<Task*> tmp = this->days[i].getTasks();
        if(!tmp.empty())
        {
            int tmp = i;
            if(i <= 9)
            {
                cout << "Tasks for 0" << tmp + 1 << " of " << this->name << ":" << endl;
            }
            else
            {
                cout << "Tasks for " << tmp + 1 << " of " << this->name << ":" << endl;
            }
        }
        this->days[i].print();
    }
}

void Month::addTask(Task* t, int d)
{
    for(unsigned int i = 0; i < this->days.size(); i++)
    {
        if(this->days[i].getDayNumber() == d)
            this->days[i].addTask(t);
    }
}

void Month::removeTask(const Task& _task)
{
    for(unsigned int i = 0; i < this->days.size(); i++)
    {
        this->days[i].removeTask(_task);
    }
}

void Month::write(ofstream& out)
{
    out << this->name << " ";
    out << this->numberOfDays << " ";
    for(unsigned int i = 0; i < this->days.size(); i++)
    {
        this->days[i].write(out);
    }
}

void Month::read(ifstream& in)
{
    in >> this->name;
    in >> this->numberOfDays;
    for(unsigned int i = 0; i < this->days.size(); i++)
    {
        this->days[i].read(in);
    }
}

void Month::setJan()
{
    this->setName("January");
    this->setNumberOfDays(31);
    int count = 1;
    for(int i = 0; i < this->numberOfDays; i++)
    {
        Day *d = new Day();
        d->setDayNumber(i + 1);
        if(count == 1)
            d->setDayInWeek("Monday");
        if(count == 2)
            d->setDayInWeek("Tuesday");
        if(count == 3)
            d->setDayInWeek("Wednesday");
        if(count == 4)
            d->setDayInWeek("Thursday");
        if(count == 5)
            d->setDayInWeek("Friday");
        if(count == 6)
            d->setDayInWeek("Saturday");
        if(count == 7)
        {
            d->setDayInWeek("Sunday");
            count = 0;
        }
        days.push_back(*d);
        count++;
    }
}

void Month::setFeb1()
{
    this->setName("February");
    this->setNumberOfDays(28);
    int count = 1;
    for(int i = 0; i < this->numberOfDays; i++)
    {
        Day *d = new Day();
        d->setDayNumber(i + 1);
        if(count == 1)
            d->setDayInWeek("Thursday");
        if(count == 2)
            d->setDayInWeek("Friday");
        if(count == 3)
            d->setDayInWeek("Saturday");
        if(count == 4)
            d->setDayInWeek("Sunday");
        if(count == 5)
            d->setDayInWeek("Monday");
        if(count == 6)
            d->setDayInWeek("Tuesday");
        if(count == 7)
        {
            d->setDayInWeek("Wednesday");
            count = 0;
        }
        days.push_back(*d);
        count++;
    }
}

void Month::setMarch1()
{
    this->setName("March");
    this->setNumberOfDays(31);
    int count = 1;
    for(int i = 0; i < this->numberOfDays; i++)
    {
        Day *d = new Day();
        d->setDayNumber(i + 1);
        if(count == 1)
            d->setDayInWeek("Thursday");
        if(count == 2)
            d->setDayInWeek("Friday");
        if(count == 3)
            d->setDayInWeek("Saturday");
        if(count == 4)
            d->setDayInWeek("Sunday");
        if(count == 5)
            d->setDayInWeek("Monday");
        if(count == 6)
            d->setDayInWeek("Tuesday");
        if(count == 7)
        {
            d->setDayInWeek("Wednesday");
            count = 0;
        }
        days.push_back(*d);
        count++;
    }
}

void Month::setApr1()
{
    this->setName("April");
    this->setNumberOfDays(30);
    int count = 1;
    for(int i = 0; i < this->numberOfDays; i++)
    {
        Day *d = new Day();
        d->setDayNumber(i + 1);
        if(count == 1)
            d->setDayInWeek("Sunday");
        if(count == 2)
            d->setDayInWeek("Monday");
        if(count == 3)
            d->setDayInWeek("Tuesday");
        if(count == 4)
            d->setDayInWeek("Wednesday");
        if(count == 5)
            d->setDayInWeek("Thursday");
        if(count == 6)
            d->setDayInWeek("Friday");
        if(count == 7)
        {
            d->setDayInWeek("Saturday");
            count = 0;
        }
        days.push_back(*d);
        count++;
    }
}

void Month::setMay1()
{
    this->setName("May");
    this->setNumberOfDays(31);
    int count = 1;
    for(int i = 0; i < this->numberOfDays; i++)
    {
        Day *d = new Day();
        d->setDayNumber(i + 1);
        if(count == 1)
            d->setDayInWeek("Tuesday");
        if(count == 2)
            d->setDayInWeek("Wednesday");
        if(count == 3)
            d->setDayInWeek("Thursday");
        if(count == 4)
            d->setDayInWeek("Friday");
        if(count == 5)
            d->setDayInWeek("Saturday");
        if(count == 6)
            d->setDayInWeek("Sunday");
        if(count == 7)
        {
            d->setDayInWeek("Monday");
            count = 0;
        }
        days.push_back(*d);
        count++;
    }
}

void Month::setJune1()
{
    this->setName("June");
    this->setNumberOfDays(30);
    int count = 1;
    for(int i = 0; i < this->numberOfDays; i++)
    {
        Day *d = new Day();
        d->setDayNumber(i + 1);
        if(count == 1)
            d->setDayInWeek("Friday");
        if(count == 2)
            d->setDayInWeek("Saturday");
        if(count == 3)
            d->setDayInWeek("Sunday");
        if(count == 4)
            d->setDayInWeek("Monday");
        if(count == 5)
            d->setDayInWeek("Tuesday");
        if(count == 6)
            d->setDayInWeek("Wednesday");
        if(count == 7)
        {
            d->setDayInWeek("Thursday");
            count = 0;
        }
        days.push_back(*d);
        count++;
    }
}

void Month::setJuly1()
{
    this->setName("July");
    this->setNumberOfDays(31);
    int count = 1;
    for(int i = 0; i < this->numberOfDays; i++)
    {
        Day *d = new Day();
        d->setDayNumber(i + 1);
        if(count == 1)
            d->setDayInWeek("Sunday");
        if(count == 2)
            d->setDayInWeek("Monday");
        if(count == 3)
            d->setDayInWeek("Tuesday");
        if(count == 4)
            d->setDayInWeek("Wednesday");
        if(count == 5)
            d->setDayInWeek("Thursday");
        if(count == 6)
            d->setDayInWeek("Friday");
        if(count == 7)
        {
            d->setDayInWeek("Saturday");
            count = 0;
        }
        days.push_back(*d);
        count++;
    }
}

void Month::setAug1()
{
    this->setName("August");
    this->setNumberOfDays(31);
    int count = 1;
    for(int i = 0; i < this->numberOfDays; i++)
    {
        Day *d = new Day();
        d->setDayNumber(i + 1);
        if(count == 1)
            d->setDayInWeek("Wednesday");
        if(count == 2)
            d->setDayInWeek("Thrusday");
        if(count == 3)
            d->setDayInWeek("Friday");
        if(count == 4)
            d->setDayInWeek("Saturday");
        if(count == 5)
            d->setDayInWeek("Sunday");
        if(count == 6)
            d->setDayInWeek("Monday");
        if(count == 7)
        {
            d->setDayInWeek("Tuesday");
            count = 0;
        }
        days.push_back(*d);
        count++;
    }
}

void Month::setSep1()
{
    this->setName("September");
    this->setNumberOfDays(30);
    int count = 1;
    for(int i = 0; i < this->numberOfDays; i++)
    {
        Day *d = new Day();
        d->setDayNumber(i + 1);
        if(count == 1)
            d->setDayInWeek("Saturday");
        if(count == 2)
            d->setDayInWeek("Sunday");
        if(count == 3)
            d->setDayInWeek("Monday");
        if(count == 4)
            d->setDayInWeek("Tuesday");
        if(count == 5)
            d->setDayInWeek("Wednesday");
        if(count == 6)
            d->setDayInWeek("Thursday");
        if(count == 7)
        {
            d->setDayInWeek("Friday");
            count = 0;
        }
        days.push_back(*d);
        count++;
    }
}

void Month::setOct1()
{
    this->setName("Octomber");
    this->setNumberOfDays(31);
    int count = 1;
    for(int i = 0; i < this->numberOfDays; i++)
    {
        Day *d = new Day();
        d->setDayNumber(i + 1);
        if(count == 1)
            d->setDayInWeek("Monday");
        if(count == 2)
            d->setDayInWeek("Tuesday");
        if(count == 3)
            d->setDayInWeek("Wednesday");
        if(count == 4)
            d->setDayInWeek("Thursday");
        if(count == 5)
            d->setDayInWeek("Friday");
        if(count == 6)
            d->setDayInWeek("Saturday");
        if(count == 7)
        {
            d->setDayInWeek("Sunday");
            count = 0;
        }
        days.push_back(*d);
        count++;
    }
}

void Month::setNov1()
{
    this->setName("November");
    this->setNumberOfDays(30);
    int count = 1;
    for(int i = 0; i < this->numberOfDays; i++)
    {
        Day *d = new Day();
        d->setDayNumber(i + 1);
        if(count == 1)
            d->setDayInWeek("Thursday");
        if(count == 2)
            d->setDayInWeek("Friday");
        if(count == 3)
            d->setDayInWeek("Saturday");
        if(count == 4)
            d->setDayInWeek("Sunday");
        if(count == 5)
            d->setDayInWeek("Monday");
        if(count == 6)
            d->setDayInWeek("Tuesday");
        if(count == 7)
        {
            d->setDayInWeek("Wednesday");
            count = 0;
        }
        days.push_back(*d);
        count++;
    }
}

void Month::setDec1()
{
    this->setName("December");
    this->setNumberOfDays(31);
    int count = 1;
    for(int i = 0; i < this->numberOfDays; i++)
    {
        Day *d = new Day();
        d->setDayNumber(i + 1);
        if(count == 1)
            d->setDayInWeek("Sunday");
        if(count == 2)
            d->setDayInWeek("Monday");
        if(count == 3)
            d->setDayInWeek("Tuesday");
        if(count == 4)
            d->setDayInWeek("Wednesday");
        if(count == 5)
            d->setDayInWeek("Thursday");
        if(count == 6)
            d->setDayInWeek("Friday");
        if(count == 7)
        {
            d->setDayInWeek("Saturday");
            count = 0;
        }
        days.push_back(*d);
        count++;
    }
}

void Month::setFeb2()
{
    this->setName("February");
    this->setNumberOfDays(29);
    int count = 1;
    for(int i = 0; i < this->numberOfDays; i++)
    {
        Day *d = new Day();
        d->setDayNumber(i + 1);
        if(count == 1)
            d->setDayInWeek("Thursday");
        if(count == 2)
            d->setDayInWeek("Friday");
        if(count == 3)
            d->setDayInWeek("Saturday");
        if(count == 4)
            d->setDayInWeek("Sunday");
        if(count == 5)
            d->setDayInWeek("Monday");
        if(count == 6)
            d->setDayInWeek("Tuesday");
        if(count == 7)
        {
            d->setDayInWeek("Wednesday");
            count = 0;
        }
        days.push_back(*d);
        count++;
    }
}

void Month::setMarch2()
{
    this->setName("March");
    this->setNumberOfDays(31);
    int count = 1;
    for(int i = 0; i < this->numberOfDays; i++)
    {
        Day *d = new Day();
        d->setDayNumber(i + 1);
        if(count == 1)
            d->setDayInWeek("Friday");
        if(count == 2)
            d->setDayInWeek("Saturday");
        if(count == 3)
            d->setDayInWeek("Sunday");
        if(count == 4)
            d->setDayInWeek("Monday");
        if(count == 5)
            d->setDayInWeek("Tuesday");
        if(count == 6)
            d->setDayInWeek("Wednesday");
        if(count == 7)
        {
            d->setDayInWeek("Thursday");
            count = 0;
        }
        days.push_back(*d);
        count++;
    }
}

void Month::setApr2()
{
    this->setName("April");
    this->setNumberOfDays(30);
    int count = 1;
    for(int i = 0; i < this->numberOfDays; i++)
    {
        Day *d = new Day();
        d->setDayNumber(i + 1);
        if(count == 1)
            d->setDayInWeek("Monday");
        if(count == 2)
            d->setDayInWeek("Tuesday");
        if(count == 3)
            d->setDayInWeek("Wednesday");
        if(count == 4)
            d->setDayInWeek("Thursday");
        if(count == 5)
            d->setDayInWeek("Friday");
        if(count == 6)
            d->setDayInWeek("Saturday");
        if(count == 7)
        {
            d->setDayInWeek("Sunday");
            count = 0;
        }
        days.push_back(*d);
        count++;
    }
}

void Month::setMay2()
{
    this->setName("May");
    this->setNumberOfDays(31);
    int count = 1;
    for(int i = 0; i < this->numberOfDays; i++)
    {
        Day *d = new Day();
        d->setDayNumber(i + 1);
        if(count == 1)
            d->setDayInWeek("Wednesday");
        if(count == 2)
            d->setDayInWeek("Thrusday");
        if(count == 3)
            d->setDayInWeek("Friday");
        if(count == 4)
            d->setDayInWeek("Saturday");
        if(count == 5)
            d->setDayInWeek("Sunday");
        if(count == 6)
            d->setDayInWeek("Monday");
        if(count == 7)
        {
            d->setDayInWeek("Tuesday");
            count = 0;
        }
        days.push_back(*d);
        count++;
    }
}

void Month::setJune2()
{
    this->setName("June");
    this->setNumberOfDays(30);
    int count = 1;
    for(int i = 0; i < this->numberOfDays; i++)
    {
        Day *d = new Day();
        d->setDayNumber(i + 1);
        if(count == 1)
            d->setDayInWeek("Saturday");
        if(count == 2)
            d->setDayInWeek("Sunday");
        if(count == 3)
            d->setDayInWeek("Monday");
        if(count == 4)
            d->setDayInWeek("Tuesday");
        if(count == 5)
            d->setDayInWeek("Wednesday");
        if(count == 6)
            d->setDayInWeek("Thursday");
        if(count == 7)
        {
            d->setDayInWeek("Friday");
            count = 0;
        }
        days.push_back(*d);
        count++;
    }
}

void Month::setJuly2()
{
    this->setName("July");
    this->setNumberOfDays(31);
    int count = 1;
    for(int i = 0; i < this->numberOfDays; i++)
    {
        Day *d = new Day();
        d->setDayNumber(i + 1);
        if(count == 1)
            d->setDayInWeek("Monday");
        if(count == 2)
            d->setDayInWeek("Tuesday");
        if(count == 3)
            d->setDayInWeek("Wednesday");
        if(count == 4)
            d->setDayInWeek("Thursday");
        if(count == 5)
            d->setDayInWeek("Friday");
        if(count == 6)
            d->setDayInWeek("Saturday");
        if(count == 7)
        {
            d->setDayInWeek("Sunday");
            count = 0;
        }
        days.push_back(*d);
        count++;
    }
}

void Month::setAug2()
{
    this->setName("August");
    this->setNumberOfDays(31);
    int count = 1;
    for(int i = 0; i < this->numberOfDays; i++)
    {
        Day *d = new Day();
        d->setDayNumber(i + 1);
        if(count == 1)
            d->setDayInWeek("Thursday");
        if(count == 2)
            d->setDayInWeek("Friday");
        if(count == 3)
            d->setDayInWeek("Saturday");
        if(count == 4)
            d->setDayInWeek("Sunday");
        if(count == 5)
            d->setDayInWeek("Monday");
        if(count == 6)
            d->setDayInWeek("Tuesday");
        if(count == 7)
        {
            d->setDayInWeek("Wednesday");
            count = 0;
        }
        days.push_back(*d);
        count++;
    }
}

void Month::setSep2()
{
    this->setName("September");
    this->setNumberOfDays(30);
    int count = 1;
    for(int i = 0; i < this->numberOfDays; i++)
    {
        Day *d = new Day();
        d->setDayNumber(i + 1);
        if(count == 1)
            d->setDayInWeek("Sunday");
        if(count == 2)
            d->setDayInWeek("Monday");
        if(count == 3)
            d->setDayInWeek("Tuesday");
        if(count == 4)
            d->setDayInWeek("Wednesday");
        if(count == 5)
            d->setDayInWeek("Thursday");
        if(count == 6)
            d->setDayInWeek("Friday");
        if(count == 7)
        {
            d->setDayInWeek("Saturday");
            count = 0;
        }
        days.push_back(*d);
        count++;
    }
}

void Month::setOct2()
{
    this->setName("Octomber");
    this->setNumberOfDays(31);
    int count = 1;
    for(int i = 0; i < this->numberOfDays; i++)
    {
        Day *d = new Day();
        d->setDayNumber(i + 1);
        if(count == 1)
            d->setDayInWeek("Tuesday");
        if(count == 2)
            d->setDayInWeek("Wednesday");
        if(count == 3)
            d->setDayInWeek("Thursday");
        if(count == 4)
            d->setDayInWeek("Friday");
        if(count == 5)
            d->setDayInWeek("Saturday");
        if(count == 6)
            d->setDayInWeek("Sunday");
        if(count == 7)
        {
            d->setDayInWeek("Monday");
            count = 0;
        }
        days.push_back(*d);
        count++;
    }
}

void Month::setNov2()
{
    this->setName("November");
    this->setNumberOfDays(30);
    int count = 1;
    for(int i = 0; i < this->numberOfDays; i++)
    {
        Day *d = new Day();
        d->setDayNumber(i + 1);
        if(count == 1)
            d->setDayInWeek("Friday");
        if(count == 2)
            d->setDayInWeek("Saturday");
        if(count == 3)
            d->setDayInWeek("Sunday");
        if(count == 4)
            d->setDayInWeek("Monday");
        if(count == 5)
            d->setDayInWeek("Tuesday");
        if(count == 6)
            d->setDayInWeek("Wednesday");
        if(count == 7)
        {
            d->setDayInWeek("Thursday");
            count = 0;
        }
        days.push_back(*d);
        count++;
    }
}

void Month::setDec2()
{
    this->setName("December");
    this->setNumberOfDays(31);
    int count = 1;
    for(int i = 0; i < this->numberOfDays; i++)
    {
        Day *d = new Day();
        d->setDayNumber(i + 1);
        if(count == 1)
            d->setDayInWeek("Sunday");
        if(count == 2)
            d->setDayInWeek("Monday");
        if(count == 3)
            d->setDayInWeek("Tuesday");
        if(count == 4)
            d->setDayInWeek("Wednesday");
        if(count == 5)
            d->setDayInWeek("Thursday");
        if(count == 6)
            d->setDayInWeek("Friday");
        if(count == 7)
        {
            d->setDayInWeek("Saturday");
            count = 0;
        }
        days.push_back(*d);
        count++;
    }
}
