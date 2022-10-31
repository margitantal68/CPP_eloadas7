#ifndef __PERSON_H
#define __PERSON_H
#include <string>
#include <ostream>

using namespace std;

struct Person{
    string firstName;
    string lastName;
    Person(const string& firstName, const string& lastName):firstName(firstName), lastName(lastName){}
};

ostream &operator<<(ostream &os, const Person &person);

#endif __PERSON_H