#include "Day.h"

void Day::copy(const Day& other)
{
    this->dayNumber = other.dayNumber;
    for(unsigned int i = 0; i < other.tasks.size(); i++)
    {
        this->tasks.push_back(other.tasks[i]);
    }
    if(other.dayInWeek == nullptr)
        this->dayInWeek = nullptr;
    else
    {
        this->dayInWeek = new char[strlen(other.dayInWeek) + 1];
        strcpy(this->dayInWeek, other.dayInWeek);
    }
}

void Day::erase()
{
    delete[] this->dayInWeek;
}

Day::Day()
{
    this->dayInWeek = new char[0];
    strcpy(this->dayInWeek, "");
    this->dayNumber = 0;
}

Day::Day(const Day& other){this->copy(other);}

Day& Day::operator=(const Day& other)
{
    if(this != &other)
    {
        this->erase();
        this->copy(other);
    }
    return *this;
}

Day::~Day(){this->erase();}

void Day::operator+(Task& task)
{
    this->tasks.push_back(&task);
}

void Day::operator-(const Task& task)
{
    for(unsigned int i = 0; i < this->tasks.size(); i++)
    {
        if(this->tasks[i] == &task)
            this->tasks.erase(this->tasks.begin() + i);
    }
}

void Day::addTask(Task* task)
{
    this->tasks.push_back(task);
}

void Day::removeTask(const Task& task)
{
    for(unsigned int i = 0; i < this->tasks.size(); i++)
    {
        if(this->tasks[i] == &task)
            this->tasks.erase(this->tasks.begin() + i);
    }
}

void Day::print()const
{
    for(unsigned int i = 0; i < this->tasks.size(); i++)
    {
        this->tasks[i]->print();
    }
}

void Day::setDayNumber(int dn)
{
    assert(dn >= 1 && dn <= 31);
    this->dayNumber = dn;
}

void Day::setDayInWeek(const char* d)
{
    this->dayInWeek = new char[strlen(d) + 1];
    strcpy(this->dayInWeek, d);

}

Task* Day::getTaskByName(const char* _name)
{
    Task* res;
    for(unsigned int i = 0; i < this->tasks.size(); i++)
    {
        if(strcmp(this->tasks[i]->getName(), _name) == 0)
            res = this->tasks[i];
    }
    return res;
}

vector<Task*> Day::getTasksByType(const char* _type)
{
    vector<Task*> res;
    for(unsigned int i = 0; i < this->tasks.size(); i++)
    {
        if(strcmp(this->tasks[i]->getType(), _type) == 0)
            res.push_back(this->tasks[i]);
    }
    return res;
}

int Day::getDayNumber()const{return this->dayNumber;}

vector<Task*> Day::getTasks()const{return this->tasks;}

char* Day::getDayInWeek()const{return this->dayInWeek;}

void Day::write(ofstream& out)
{
    out << this->dayInWeek << " ";
    out << this->dayNumber << " ";
    for(unsigned int i = 0; i < this->tasks.size(); i++)
    {
        this->tasks[i]->write(out);
    }
}

void Day::read(ifstream& in)
{
    in >> this->dayInWeek;
    in >> this->dayNumber;
    for(unsigned int i = 0; i < this->tasks.size(); i++)
    {
        this->tasks[i]->read(in);
    }
}






