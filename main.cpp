#include <iostream>
#include "Person.h"
#include <vector>
#include <set>

using namespace std;

struct PersonComp{
    bool operator()( const Person& p1, const Person& p2){
        if( p1.firstName == p2.firstName){
            return p1.lastName < p2.lastName;
        }
        return p1.firstName < p2.firstName;
    }
};

void printPersons(const vector<Person>& persons){
    for(auto& pers: persons){
        cout << "\t" << pers<<endl;
    }
}

void printPersonSet(const set<Person, PersonComp>& persons){
    for(auto& pers: persons){
        cout << "\t" << pers<<endl;
    }
}

int main() {
    vector<Person> persons {
            {"Jakab", "Antal"},
            {"Bereczki", "Lujza"},
            {"Nemes", "Szidonia"},
            {"Antal", "Barnabas"}
    };
    cout<<"# Data"<<endl;
    printPersons(persons);

    cout << endl <<"# Searching"<<endl;
    string toFind = "tal";
    cout <<"## Persons whose name contains " << toFind <<": "<<endl;
    for(auto& pers: persons){
        if(pers.firstName.find(toFind) != string::npos ||
                pers.lastName.find(toFind) != string::npos
        ){
            cout << "\t" << pers<<endl;
        }
    }
    cout<<endl << "# Using set for sorting: " <<endl;
    set<string> names;
    for(auto& pers: persons){
        names.insert(pers.firstName);
        names.insert(pers.lastName);
    }
    cout <<"## Unique names: " << names.size()<<endl;
    set<Person, PersonComp> personSet;
    for(auto& pers: persons){
        personSet.insert(pers);
    }
    cout << "## Sorted persons: "<<endl;
    printPersonSet(personSet);
    return 0;
}
