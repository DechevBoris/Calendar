#pragma once
#include "Month.h"

class Calendar
{
private:
    char* description;
    int year;
    Month months[12];

    void copy(const Calendar& other);
    void erase();
public:
    Calendar();
    Calendar(int _year);
    Calendar(const Calendar& other);
    Calendar& operator=(const Calendar& other);
    ~Calendar();
    void setYear(int _year);
    void setDescription(const char* _description);
    int getYear()const;
    char* getDescription()const;
    void print()const;
    void printTaskByDate(int _day, int _month)const;
    void addTask(Task* _task, int _day, int _month);
    void removeTask(const Task& _task);
    void write();
    void read();
};
