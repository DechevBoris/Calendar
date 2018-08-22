#pragma once
#include "Task.h"
#include <vector>

class Day
{
private:
    char* dayInWeek;
    int dayNumber;
    vector<Task*> tasks;

    void copy(const Day& other);
    void erase();
public:
    Day();
    Day(const Day& other);
    Day& operator=(const Day& other);
    ~Day();
    void operator+(Task& task);
    void operator-(const Task& task);
    void addTask(Task* task);
    void removeTask(const Task& task);
    void print()const;
    void setDayNumber(int dn);
    void setDayInWeek(const char* d);
    Task* getTaskByName(const char* _name);
    vector<Task*> getTasksByType(const char* _type);
    int getDayNumber()const;
    vector<Task*> getTasks()const;
    char* getDayInWeek()const;
    void write(ofstream& out);
    void read(ifstream& in);
};
