#pragma once
#include "Task.h"


class EntertainmentTask : public Task
{
private:
    char* typeOfEntertainment;
    char* destination;

    void copy(const EntertainmentTask& other);
    void erase();
public:
    EntertainmentTask();
    EntertainmentTask(const EntertainmentTask& other);
    EntertainmentTask& operator=(const EntertainmentTask& other);
    ~EntertainmentTask();
    void setTypeOfEntertainment(const char* type);
    void setDestination(const char* _destination);
    char* getTypeOfEntertainment()const;
    char* getDestination()const;
    void print()const;
    void checkTheWeather();
    void setType();
    bool operator==(Task& other);
    void write(ofstream& out);
    void write();
    void read(ifstream& in);
};
