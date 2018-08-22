#include "EntertainmentTask.h"

void EntertainmentTask::copy(const EntertainmentTask& other)
{
    if(other.typeOfEntertainment == nullptr)
        this->typeOfEntertainment = nullptr;
    else
    {
        this->typeOfEntertainment = new char[strlen(other.typeOfEntertainment) + 1];
        strcpy(this->typeOfEntertainment, other.typeOfEntertainment);
    }
    if(other.destination == nullptr)
        this->destination = nullptr;
    else
    {
        this->destination = new char[strlen(other.destination) + 1];
        strcpy(this->destination, other.destination);
    }
}

void EntertainmentTask::erase()
{
    delete[] this->typeOfEntertainment;
    delete[] this->destination;
}

EntertainmentTask::EntertainmentTask() : Task()
{
    this->typeOfEntertainment = new char[0];
    strcpy(this->typeOfEntertainment, "");
    this->destination = new char[0];
    strcpy(this->destination, "");
    this->setType();
}

EntertainmentTask::EntertainmentTask(const EntertainmentTask& other) : Task(other)
{
    this->copy(other);
}

EntertainmentTask& EntertainmentTask::operator=(const EntertainmentTask& other)
{
    if(this != &other)
    {
        Task::operator=(other);
        this->copy(other);
    }
    return *this;
}

EntertainmentTask::~EntertainmentTask()
{
    this->erase();
}

void EntertainmentTask::setTypeOfEntertainment(const char* type)
{
    this->typeOfEntertainment = new char[strlen(type) + 1];
    strcpy(this->typeOfEntertainment, type);
}

void EntertainmentTask::setDestination(const char* _destination)
{
    this->destination = new char[strlen(_destination) + 1];
    strcpy(this->destination, _destination);
}

char* EntertainmentTask::getTypeOfEntertainment()const{return this->typeOfEntertainment;}

char* EntertainmentTask::getDestination()const{return this->destination;}

void EntertainmentTask::print()const
{
    Task::print();
    cout << "Type of entertainment: " << this->typeOfEntertainment << endl;
    cout << "Destination: " << this->destination << endl;
    cout << endl;
}

void EntertainmentTask::checkTheWeather()
{
    string fst = "start chrome https://www.sinoptik.bg/search?q={";
    fst += this->destination;
    string snd = "}";
    fst += snd;
    system(fst.c_str());
}

void EntertainmentTask::setType()
{
    this->type = new char[14];
    strcpy(this->type, "entertainment");
}

bool EntertainmentTask::operator==(Task& other)
{
    if(!strcmp(this->getType(), other.getType()) == 0)
        return false;
    EntertainmentTask* tmp = dynamic_cast<EntertainmentTask*>(&other);
    return (strcmp(this->getDescription(), tmp->getDescription()) == 0 &&
            strcmp(this->getName(), tmp->getName()) == 0 &&
            this->getDiapason() == tmp->getDiapason() &&
            strcmp(this->typeOfEntertainment, tmp->typeOfEntertainment) == 0 &&
            strcmp(this->destination, tmp->destination) == 0);
}

void EntertainmentTask::write(ofstream& out)
{
    out << this->getType() << " ";
    out << this->getName() << " ";
    out << this->getDescription() << " ";
    this->getDiapason().write(out);
    out << this->typeOfEntertainment << " ";
    out << this->destination << " ";
}

void EntertainmentTask::write()
{
    ofstream out("entertainmentTask.txt");
    out << this->getType() << endl;
    out << this->getName() << endl;
    out << this->getDescription() << endl;
    this->getDiapason().write(out);
    out << this->typeOfEntertainment << endl;
    out << this->destination << endl;
}

void EntertainmentTask::read(ifstream& in)
{
    Task::read(in);
    in >> this->typeOfEntertainment;
    in >> this->destination;
}
