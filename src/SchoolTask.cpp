#include "SchoolTask.h"

void SchoolTask::copy(const SchoolTask& other)
{
    if(other.subjectName == nullptr)
        this->subjectName = nullptr;
    else
    {
        this->subjectName = new char[strlen(other.subjectName) + 1];
        strcpy(this->subjectName, other.subjectName);
    }
    if(other.mustReadMaterial == nullptr)
        this->mustReadMaterial = nullptr;
    else
    {
        this->mustReadMaterial = new char[strlen(other.mustReadMaterial) + 1];
        strcpy(this->mustReadMaterial, other.mustReadMaterial);
    }
}

void SchoolTask::erase()
{
    delete[] this->subjectName;
    delete[] this->mustReadMaterial;
}

SchoolTask::SchoolTask() : Task()
{
    this->subjectName = new char[0];
    strcpy(this->subjectName, "");
    this->mustReadMaterial = new char[0];
    strcpy(this->mustReadMaterial, "");
    this->setType();
}

SchoolTask::SchoolTask(const SchoolTask& other) : Task(other)
{
    this->copy(other);
}

SchoolTask& SchoolTask::operator=(const SchoolTask& other)
{
    if(this != &other)
    {
        Task::operator=(other);
        this->copy(other);
    }
    return *this;
}

SchoolTask::~SchoolTask()
{
    this->erase();
}

void SchoolTask::setSubjectName(const char* subject)
{
    this->subjectName = new char[strlen(subject) + 1];
    strcpy(this->subjectName, subject);
}

void SchoolTask::setMustReadMaterial(const char* material)
{
    this->mustReadMaterial = new char[strlen(material) + 1];
    strcpy(this->mustReadMaterial, material);
}
char* SchoolTask::getSubjectName()const{return this->subjectName;}

char* SchoolTask::getMustReadMaterial()const{return this->mustReadMaterial;}

void SchoolTask::print()const
{
    Task::print();
    cout << "Subject name: " << this->subjectName << endl;
    cout << "Must-read material: " << this->mustReadMaterial << endl;
    cout << endl;
}

void SchoolTask::setType()
{
    this->type = new char[7];
    strcpy(this->type, "school");
}


bool SchoolTask::operator==(Task& other)
{
    if(!strcmp(this->getType(), other.getType()) == 0)
        return false;
    SchoolTask* tmp = dynamic_cast<SchoolTask*>(&other);
    return (strcmp(this->getDescription(), tmp->getDescription()) == 0 &&
            strcmp(this->getName(), tmp->getName()) == 0 &&
            this->getDiapason() == tmp->getDiapason() &&
            strcmp(this->subjectName, tmp->subjectName) == 0 &&
            strcmp(this->mustReadMaterial, tmp->mustReadMaterial) == 0);
}

void SchoolTask::write(ofstream& out)
{
    out << this->getType() << " ";
    out << this->getName() << " ";
    out << this->getDescription() << " ";
    this->getDiapason().write(out);
    out << this->subjectName << " ";
    out << this->mustReadMaterial << " ";
}

void SchoolTask::write()
{
    ofstream out("schoolTask.txt");
    out << this->getType() << endl;
    out << this->getName() << endl;
    out << this->getDescription() << endl;
    this->getDiapason().write(out);
    out << this->subjectName << endl;
    out << this->mustReadMaterial << endl;
}

void SchoolTask::read(ifstream& in)
{
    Task::read(in);
    in >> this->subjectName;
    in >> this->mustReadMaterial;
}
