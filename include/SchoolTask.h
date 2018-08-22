#pragma once
#include "Task.h"


class SchoolTask : public Task
{
private:
    char* subjectName;
    char* mustReadMaterial;

    void copy(const SchoolTask& other);
    void erase();
public:
    SchoolTask();
    SchoolTask(const SchoolTask& other);
    SchoolTask& operator=(const SchoolTask& other);
    ~SchoolTask();
    void setSubjectName(const char* subject);
    void setMustReadMaterial(const char* material);
    char* getSubjectName()const;
    char* getMustReadMaterial()const;
    void print()const;
    void setType();
    bool operator==(Task& other);
    void write(ofstream& out);
    void write();
    void read(ifstream& in);
};
