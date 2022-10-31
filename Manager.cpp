//
// Created by Margit Antal on 31.10.2022.
//

#include "Manager.h"

Manager::Manager(const string &firstName, const string &lastName, const string &department) : Person(firstName,
                                                                                                     lastName),
                                                                                              department(department) {}
