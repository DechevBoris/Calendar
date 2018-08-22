#pragma once
#include "Task.h"
#include "Person.h"

class BusinessTask : public Task
{
private:
    vector<Person> people;
    char* location;
    char* host;

    void copy(const BusinessTask& other);
    void erase();
public:
    BusinessTask();
    BusinessTask(const BusinessTask& other);
    BusinessTask& operator=(const BusinessTask& other);
    ~BusinessTask();
    void operator+(const Person& person);
    void operator-(Person& person);
    void setPeople(vector<Person> _people);
    void setLocation(const char* _location);
    void setHost(const char* _host);
    Time getDuration()const;
    vector<Person> getPeople()const;
    char* getLocation()const;
    char* getHost()const;
    void print()const;
    void setType();
    bool operator==(Task& other);
    void write(ofstream& out);
    void write();
    void read(ifstream& in);
};
