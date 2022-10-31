#include "Person.h"
#include <iostream>

using namespace std;

ostream &operator<<(ostream &os, const Person &person) {
    os << person.firstName << " " << person.lastName;
    return os;
}

