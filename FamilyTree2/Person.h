#include <string>
#include <iostream>
#include <vector>
//#include "utility.h"

using namespace std;

class Person {
private:
    string firstname_;
    string lastname_;
    string gender_;
    int birthYear_;
    int deathYear_;
    vector<Person *> children; //create vector of pointers children
    Person* Parent;
public:
    Person();
    Person(
            string firstname,
            string lastname,
            string gender,
            int birthYear,
            int deathYear);

    void traverse();
    void breadthFirstTraverse();

    string getFirstName();

    string getLastName();

    string getGender();

    void setParent(Person* newParent);

    int getBirthYear();

    int getDeathYear();

    void addChild(Person* nextPerson);      //declare function to make child
    void addChild(string firstname,string lastname, string gender, int birthYear, int deathYear);
    string printPerson();
    Person* selectChild (string Firstname, string Lastname);
    Person* findPerson (string Firstname, string Lastname, bool &PersonFound);

    friend ostream &operator<<(ostream &os, const Person &c);

};