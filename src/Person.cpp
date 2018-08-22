#include "Person.h"

void Person::copy(const Person& other)
{
    if(other.fstName == nullptr)
        this->fstName = nullptr;
    else
    {
        this->fstName = new char[strlen(other.fstName) + 1];
        strcpy(this->fstName, other.fstName);
    }
    if(other.lastName == nullptr)
        this->lastName = nullptr;
    else
    {
        this->lastName = new char[strlen(other.lastName) + 1];
        strcpy(this->lastName, other.lastName);
    }
}

void Person::erase()
{
    delete[] this->fstName;
    delete[] this->lastName;
}

Person::Person()
{
    this->fstName = nullptr;
    this->lastName = nullptr;
}

Person::Person(const Person& other){this->copy(other);}

Person& Person::operator=(const Person& other)
{
    if(this != &other)
    {
        this->erase();
        this->copy(other);
    }
    return *this;
}

Person::~Person()
{
    this->erase();
}

void Person::setFstName(const char* fst)
{
    this->fstName = new char[strlen(fst) + 1];
    strcpy(this->fstName, fst);
}

void Person::setLastName(const char* last)
{
    this->lastName = new char[strlen(last) + 1];
    strcpy(this->lastName, last);
}

char* Person::getFstName()const{return this->fstName;}

char* Person::getLastName()const{return this->lastName;}

void Person::print()const
{
    cout << this->fstName << " " << this->lastName;
}

bool Person::operator==(const Person other)
{
    return (strcmp(this->fstName,other.fstName) == 0 && strcmp(this->lastName, other.lastName) == 0);
}

bool Person::operator!=(const Person other)
{
    return !(strcmp(this->fstName,other.fstName) == 0 && strcmp(this->lastName, other.lastName) == 0);
}

void Person::write(ofstream& out)
{
    out << this->fstName << " ";
    out << this->lastName << " ";
}

void Person::read(ifstream& in)
{
    in >> this->fstName;
    in >> this->lastName;
}

