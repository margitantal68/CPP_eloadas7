//
// Created by Margit Antal on 31.10.2022.
//

#ifndef ELOADAS7_MANAGER_H
#define ELOADAS7_MANAGER_H


#include "Person.h"

struct Manager: public Person {
    string department;
    Manager(const string &firstName, const string &lastName, const string &department);
};


#endif //ELOADAS7_MANAGER_H
