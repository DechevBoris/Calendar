#include "Task.h"

void Task::copy(const Task& other)
{
    if(other.name == nullptr)
        this->name = nullptr;
    else
    {
        this->name = new char[strlen(other.name) + 1];
        strcpy(this->name, other.name);
    }
    if(other.description == nullptr)
        this->description = nullptr;
    else
    {
        this->description = new char[strlen(other.description) + 1];
        strcpy(this->description, other.description);
    }
    this->diapason = other.diapason;
    if(other.type == nullptr)
        this->type = nullptr;
    else
    {
        this->type = new char[strlen(other.type) + 1];
        strcpy(this->type, other.type);
    }
}

void Task::erase()
{
    delete[] this->name;
    delete[] this->description;
    delete[] this->type;
}

Task::Task()
{
    this->name = new char[0];
    strcpy(this->name, "");
    this->description = new char[0];
    strcpy(this->description, "");
    this->type = new char[8];
    strcpy(this->type, "default");
    this->tasksCount++;
}

Task::Task(const Task& other)
{
    this->copy(other);
    this->tasksCount++;
}

Task& Task::operator=(const Task& other)
{
    if(this != &other)
    {
        this->erase();
        this->copy(other);
    }
    return *this;
}

Task::~Task(){this->erase();}

void Task::setName(const char* _name)
{
    this->name = new char[strlen(_name) + 1];
    strcpy(this->name, _name);
}

void Task::setDescription(const char* _description)
{
    this->description = new char[strlen(_description) + 1];
    strcpy(this->description, _description);
}

void Task::setDiapason(const Diapason d)
{
    this->diapason = d;
}

char* Task::getName()const{return this->name;}

char* Task::getDescription()const{return this->description;}

Diapason Task::getDiapason()const{return this->diapason;}

char* Task::getType()const{return this->type;}

void Task::print()const
{
    if(this->name == nullptr)
        cout << "Task name:  ,\n";
    else
        cout << "Task name: " << this->name << ",\n";
    if(this->description == nullptr)
        cout << "Task description:  ,\n";
    else
        cout << "Task description: " << this->description << ",\n";
    cout << "Task diapason: ";
    this->diapason.print();
    cout << ",\n";
    if(this->type == nullptr)
        cout << "Task type:  ,\n";
    else
        cout << "Task type: " << this->type << ",\n";
}

void Task::read(ifstream& in)
{
    in >> this->type;
    in >> this->name;
    in >> this->description;
    this->diapason.read(in);
}








