#pragma once
#include <cstring>
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class Person
{
private:
    char* fstName;
    char* lastName;

    void copy(const Person& other);
    void erase();
public:
    Person();
    Person(const Person& other);
    Person& operator=(const Person& other);
    ~Person();
    void setFstName(const char* fst);
    void setLastName(const char* last);
    char* getFstName()const;
    char* getLastName()const;
    void print()const;
    bool operator==(const Person other);
    bool operator!=(const Person other);
    void write(ofstream& out);
    void read(ifstream& in);
};

