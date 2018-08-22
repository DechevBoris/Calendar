#pragma once
#include "Diapason.h"
#include <fstream>

class Task
{
protected:
    char* type;
private:
    char* name;
    char* description;
    Diapason diapason;
    static size_t tasksCount;

    void copy(const Task& other);
    void erase();
public:
    Task();
    Task(const Task& other);
    virtual Task& operator=(const Task& other);
    ~Task();
    void setName(const char* _name);
    void setDescription(const char* _description);
    void setDiapason(const Diapason d);
    virtual void setType() = 0;
    char* getName()const;
    char* getDescription()const;
    Diapason getDiapason()const;
    char* getType()const;
    static size_t getTasksCount(){return tasksCount;}
    virtual void print()const;
    virtual bool operator==(Task& other) = 0;
    virtual void write(ofstream& out) = 0;
    virtual void write() = 0;
    virtual void read(ifstream& in);
};
