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
        cout << pers<<endl;
    }
}

void printPersonSet(const set<Person, PersonComp>& persons){
    for(auto& pers: persons){
        cout << pers<<endl;
    }
}


int main() {
    vector<Person> persons {
            {"Jakab", "Antal"},
            {"Bereczki", "Lujza"},
            {"Nemes", "Szidonia"},
            {"Antal", "Barnabas"}
    };
    printPersons(persons);
    string toFind = "tal";
    cout <<"Persons containing " << toFind <<": "<<endl;
    for(auto& pers: persons){
        if(pers.firstName.find(toFind) != string::npos ||
                pers.lastName.find(toFind) != string::npos
        ){
            cout<<pers<<endl;
        }
    }
    set<string> names;
    for(auto& pers: persons){
        names.insert(pers.firstName);
        names.insert(pers.lastName);
    }
    cout <<"Unique names: " << names.size()<<endl;
    set<Person, PersonComp> personSet;
    for(auto& pers: persons){
        personSet.insert(pers);
    }
    printPersonSet(personSet);
    return 0;
}
