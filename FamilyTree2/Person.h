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
    Person* Parent_;
public:
    Person();
    Person(
            string firstname,
            string lastname,
            string gender,
            string birthYear,
            string deathYear,
            Person* Parent= nullptr);
    ~Person();

    void traverse(int nIndent = 0);
    void breadthFirstTraverse(int nIndent = 0);
    //void printByGeneration(vector<Person *> &AllChildren);
    //void printByGeneration(Person* Tree);
    string getFirstName();
    string getLastName();
    string getGender();
    Person* getParent();
    string getBirthYear();
    string getDeathYear();

    void setFirstName(string FirstName);
    void setLastName(string LastName);
    void setGender(string Gender);
    void setBirthYear(string BirthYear);
    void setDeathYear(string DeathYear);
    void setParent(Person* newParent);


    void addChild(Person* nextPerson);      //declare function to make child
    void addChild(string firstname,string lastname, string gender, string birthYear, string deathYear);
    string printPerson();
    void findPerson (string Firstname, string Lastname, Person* &pReturnPerson);
    void removePerson ();
    void editPerson();
    friend ostream &operator<<(ostream &os, const Person &c);

};