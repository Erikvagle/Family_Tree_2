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
    string birthYear_;
    string deathYear_;
    vector<Person *> children; //create vector of pointers children
    Person* Parent;
public:
    Person();
    Person(
            string firstname,
            string lastname,
            string gender,
            string birthYear,
            string deathYear);
    ~Person();

    void traverse(int nIndent = 0);
    void breadthFirstTraverse(int nIndent = 0);

    string getFirstName();

    string getLastName();

    string getGender();

    void setParent(Person* newParent);

    string getBirthYear();

    string getDeathYear();

    void addChild(Person* nextPerson);      //declare function to make child
    void addChild(string firstname,string lastname, string gender, string birthYear, string deathYear);
    string printPerson();
    Person* selectChild (string Firstname, string Lastname);
    Person* findPerson (string Firstname, string Lastname, bool &PersonFound);
    void findPerson2 (string Firstname, string Lastname, Person* &pReturnPerson);
    friend ostream &operator<<(ostream &os, const Person &c);

};