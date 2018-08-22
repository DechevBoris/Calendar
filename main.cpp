#include "BusinessTask.h"
#include "SchoolTask.h"
#include "EntertainmentTask.h"
#include "Day.h"
#include "Calendar.h"

size_t Task::tasksCount = 0;

int main()
{
    cout << "Hello world!" << endl;
    /*
    BusinessTask b;
    Person p1,p2,p3;
    p1.setFstName("gosho");
    p1.setLastName("goshov");
    p2.setFstName("petar");
    p2.setLastName("petrov");
    p3.setFstName("ivan");
    p3.setLastName("ivanov");
    b + p1;
    b + p2;
    b + p3;
    b.print();
    b - p3;
    b.print();
    */
    /*
    BusinessTask t;
    t.setName("ime");
    t.setDescription("opisanie");
    Time t1(12,0,0);
    Time t2(15,0,0);
    Diapason d(t1,t2);
    t.setDiapason(d);
    t.setType("tip");
    Person p1,p2,p3;
    p1.setFstName("gosho");
    p1.setLastName("goshov");
    p2.setFstName("petar");
    p2.setLastName("petrov");
    p3.setFstName("ivan");
    p3.setLastName("ivanov");
    vector<Person> v;
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    t.setPeople(v);
    t.setLocation("lokacia");
    t.setHost("domakin");
    BusinessTask ta(t);
    ta.print();
    */
    /*string fst = "start chrome https://www.sinoptik.bg/search?q={";
    string snd;
    cin >> snd;
    fst += snd;
    string trd = "}";
    fst += trd;
    system(fst.c_str());
*/
/*
    EntertainmentTask e;
    e.setTypeOfEntertainment("vid");
    e.setDestination("varna");
    e.print();
    e.checkTheWeather();
*//*
    vector<Task*> tasks;
    BusinessTask b;
    b.setHost("domakin");
    SchoolTask s;
    tasks.push_back(&b);
    tasks.push_back(&s);
    for(unsigned int i = 0; i < tasks.size(); i++)
    {
        tasks[i]->print();
    }
    */
    /*
    Day d1;
    BusinessTask t1;
    t1.setHost("goso");
    t1.setName("ime1");
    SchoolTask t2;
    t2.setName("ime2");
    t2.setMustReadMaterial("kolo");
    d1 + t1;
    d1 + t2;
    d1.print();
    cout << endl;
    d1.getTaskByName("ime2")->print();
    cout << endl;
    cout << endl;
    vector<Task*> aa = d1.getTasksByType("business");
    for(unsigned int i = 0; i < aa.size(); i++)
    {
        aa[i]->print();
    }
    *//*
    Person p1,p2;
    p1.setFstName("pruv");
    p1.setLastName("pruv1");
    p2.setFstName("vtori");
    p2.setLastName("vtori1");

    Day d;
    BusinessTask t1;
    SchoolTask t2;
    EntertainmentTask t3;
    t1.setName("biznes");
    t2.setName("uchebna");
    t3.setName("razvlekatelna");
    t1 + p1;
    t1 + p2;
    t1.setHost("domakin");
    t2.setMustReadMaterial("zachetene");
    t2.setSubjectName("predmet");
    t3.setDestination("plovdiv");
    t3.setTypeOfEntertainment("razvlechenie");
    d + t1;
    d + t2;
    Calendar c(2018);
    c.print();

*/
/*
    BusinessTask b;
    b.setName("ss");
    SchoolTask t;
    t.setName("bb");
    EntertainmentTask e;
    e.setName("ee");
    Calendar c(2018);
    c.addTask(&b, 4, 7);
    c.addTask(&t, 1, 1);
    c.addTask(&e, 1,1);
    c.print();
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    Calendar c1(c);
    c1.print();
*/
/*
    BusinessTask b1;
    b1.setName("b1name");
    b1.setHost("domakin");
    Person p1;
    p1.setFstName("p1fst");
    p1.setLastName("p1last");
    vector<Person> vec;
    vec.push_back(p1);
    b1.setPeople(vec);
    b1.print();
    cout << endl;
    cout << endl;
    cout << endl;
    BusinessTask b2;
    b2 = b1;
    *//*
    Day d;
    d.setDayNumber(2);
    BusinessTask b1;
    b1.setName("b1name");
    b1.setHost("domakin");
    Person p1;
    p1.setFstName("p1fst");
    p1.setLastName("p1last");
    vector<Person> vec;
    vec.push_back(p1);
    b1.setPeople(vec);
    EntertainmentTask e;
    e.setName("ee");
    d + b1;
    d + e;
    d.print();
    cout << endl;
    cout << endl;
    cout << endl;
    Day d2;
    d2 = d;
    d2.print();
*/
/*
    Month m;
    m.setNumberOfDays(30);
    BusinessTask b;
    b.setName("ss");
    SchoolTask t;
    t.setName("bb");
    m.addTask(&b, 3);
    m.addTask(&t, 4);
    //m.print();
    cout << endl;
    cout << endl;
    cout << endl;
    Month m1;
    m1 = m;
    //m1.print();
    vector<Day> vec = m.getDays();
    for(unsigned int i = 0; i < vec.size(); i++)
    {
        vec[i].print();
    }
*/
/*
    BusinessTask b;
    b.setName("ss");
    b.setHost("host");
    SchoolTask t;
    t.setName("bb");
    EntertainmentTask e;
    e.setName("ee");
    Calendar c(2016);
    c.print();
    cout << endl;
    ofstream write("myfile.txt");
    c.write(write);
    write.close();*/

    BusinessTask b;
    b.setName("zadacha");
    b.setDescription("opisanie");
    Time t1(12,30,0);
    Time t2(13,30,0);
    Diapason d(t1,t2);
    b.setDiapason(d);
    Person p1,p2;
    p1.setFstName("gosho");
    p1.setLastName("goshov");
    p2.setFstName("pesho");
    p2.setLastName("peshov");
    b + p1;
    b + p2;
    b.setHost("domakin");
    b.setLocation("lokaciq");


    SchoolTask s;
    s.setName("zadacha");
    s.setDescription("opisanie");
    Time t3(12,30,0);
    Time t4(13,30,0);
    Diapason d1(t3,t4);
    s.setDiapason(d1);
    s.setSubjectName("predmet");
    s.setMustReadMaterial("material");


    EntertainmentTask e;
    e.setName("zadacha");
    e.setDescription("opisanie");
    Time t5(12,30,0);
    Time t6(13,30,0);
    Diapason d2(t5,t6);
    e.setDiapason(d2);
    e.setTypeOfEntertainment("futbol");
    e.setDestination("Stara Zagora");


    Day day;
    day.addTask(&b);
    day.addTask(&s);
    day.addTask(&e);

    Calendar c(2016);
    c.setDescription("des");
    c.addTask(&b, 2, 1);
    c.addTask(&s, 21, 7);
    c.addTask(&e, 13,12);
    c.write();


    Calendar c2(2016);
    c2.read();
    c2.print();

    return 0;
}
