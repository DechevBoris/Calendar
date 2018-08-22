#include "BusinessTask.h"

void BusinessTask::copy(const BusinessTask& other)
{
    this->people = other.people;
    if(other.location == nullptr)
        this->location = nullptr;
    else
    {
        this->location = new char[strlen(other.location) + 1];
        strcpy(this->location, other.location);
    }
    if(other.host == nullptr)
        this->host = nullptr;
    else
    {
        this->host = new char[strlen(other.host) + 1];
        strcpy(this->host, other.host);
    }
}

void BusinessTask::erase()
{
    delete[] this->location;
    delete[] this->host;
}

BusinessTask::BusinessTask() : Task()
{
    this->location = new char[0];
    strcpy(this->location , "");
    this->host = new char[0];
    strcpy(this->host, "");
    this->setType();
}

BusinessTask::BusinessTask(const BusinessTask& other) : Task(other) {this->copy(other);}

BusinessTask& BusinessTask::operator=(const BusinessTask& other)
{
    if(this != &other)
    {
        Task::operator=(other);
        this->copy(other);
    }
    return *this;
}

BusinessTask::~BusinessTask(){this->erase();}

void BusinessTask::operator+(const Person& person)
{
    this->people.push_back(person);
}

void BusinessTask::operator-(Person& person)
{
    for(unsigned int i = 0; i < this->people.size(); i++)
    {
        if(person == this->people[i])
            this->people.erase(this->people.begin() + i);
    }
}

void BusinessTask::setPeople(vector<Person> _people)
{
    this->people = _people;
}

void BusinessTask::setLocation(const char* _location)
{
    this->location = new char[strlen(_location) + 1];
    strcpy(this->location, _location);
}

void BusinessTask::setHost(const char* _host)
{
    this->host = new char[strlen(_host) + 1];
    strcpy(this->host, _host);
}

Time BusinessTask::getDuration()const{return this->getDiapason().getPeriod();}

vector<Person> BusinessTask::getPeople()const{return this->people;}

char* BusinessTask::getLocation()const{return this->location;}

char* BusinessTask::getHost()const{return this->host;}

void BusinessTask::print()const
{
    Task::print();
    cout << "The people on the meeting:" << endl;
    for(unsigned int i = 0; i < this->people.size(); i++)
    {
        this->people[i].print();
        cout << ", ";
    }
    cout << endl;
    cout << "Location: " << this->location << endl;
    cout << "Host: " << this->host << endl;
    cout << endl;
}

void BusinessTask::setType()
{
    this->type = new char[9];
    strcpy(this->type, "business");
}

bool BusinessTask::operator==(Task& other)
{
    if(!strcmp(this->getType(), other.getType()) == 0)
        return false;
    BusinessTask* tmp = dynamic_cast<BusinessTask*>(&other);
    if(this->people.size() != tmp->people.size())
        return false;
    for(unsigned int i = 0; i < this->people.size(); i++)
    {
        if(this->people[i] != tmp->people[i])
            return false;
    }
    return (strcmp(this->getDescription(), tmp->getDescription()) == 0 &&
            strcmp(this->getName(), tmp->getName()) == 0 &&
            this->getDiapason() == tmp->getDiapason() &&
            strcmp(this->location, tmp->location) == 0 &&
            strcmp(this->host, tmp->host) == 0);
}

void BusinessTask::write(ofstream& out)
{
    out << this->getType() << " ";
    out << this->getName() << " ";
    out << this->getDescription() << " ";
    this->getDiapason().write(out);
    for(unsigned int i = 0; i < this->people.size(); i++)
    {
        this->people[i].write(out);
    }
    out << this->location << " ";
    out << this->host << " ";
}

void BusinessTask::write()
{
    ofstream out("businessTask.txt");
    out << this->getType() << endl;
    out << this->getName() << endl;
    out << this->getDescription() << endl;
    this->getDiapason().write(out);
    for(unsigned int i = 0; i < this->people.size(); i++)
    {
        this->people[i].write(out);
    }
    out << this->location << endl;
    out << this->host << endl;
}

void BusinessTask::read(ifstream& in)
{
    Task::read(in);
    for(unsigned int i = 0; i < this->people.size(); i++)
    {
        this->people[i].read(in);
    }
    in >> this->location;
    in >> this->host;
}

