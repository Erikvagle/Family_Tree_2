#include "Person.h"

Person::Person(std::string firstname, std::string lastname, std::string gender, int birthYear, int deathYear) {
    // Constructor assigning initial values
    firstname_ = firstname;
    lastname_ = lastname;
    gender_ = gender;
    birthYear_ = birthYear;
    deathYear_ = deathYear;
    children = vector<Person *>();
    Parent = nullptr;
}

void Person::traverse(){
    //Depth-first-traversal and print
    if (children.empty() == true) {
        cout << firstname_ << "," << lastname_ << "," << gender_ << "," << birthYear_ << "," << deathYear_ << endl;
    }
    else{
        for (int i = 0; i<children.size(); i++){
            children[i]->traverse();
        }
        cout << firstname_ << "," << lastname_ << "," << gender_ << "," << birthYear_ << "," << deathYear_ << endl;
    }
}

void Person::breadthFirstTraverse(){
    //breadth-first-traversal and print

    std::cout << firstname_ << "," << lastname_ << "," << gender_ << "," << birthYear_ << "," << deathYear_ << endl;
    if (children.empty() == false) {
        for (int i = 0; i < children.size(); i++) {
            children[i]->breadthFirstTraverse();
        }
    }
}


std::string Person::getFirstName() {
        return firstname_;
    }

std::string Person::getLastName() {
        return lastname_;
    }

std::string Person::getGender() {
        return gender_;
    }

void Person::setParent(Person* newParent){
    Parent = newParent;
}

int Person::getBirthYear() {
        return birthYear_;
    }

int Person::getDeathYear() {
        return deathYear_;
    }


void Person::addChild(Person* nextPerson){
    //add existing child to a person
    nextPerson->setParent(this);
    children.push_back(nextPerson);
}
void Person::addChild(std::string firstname, std::string lastname, std::string gender, int birthYear, int deathYear){
    //create and add a new child to person
    Person* newChild = new Person(firstname, lastname, gender, birthYear, deathYear);
    newChild->setParent(this);
    children.push_back(newChild);
}

Person* Person::selectChild (string FirstName, string LastName) {
    // select child from name return nullptr if child does not exist
    Person* currentChild;
    Person* returnChild = nullptr;
    if (children.empty() == false)  {
        for (int i = 0; i<children.size(); i++){
            currentChild = children[i];
            string currentFirstName = currentChild-> getFirstName();
            string currentLastName = currentChild->getLastName();
            if ((currentFirstName == FirstName) && (currentLastName == LastName) )
                returnChild = currentChild;
            }
        }
    return returnChild;
}

Person* Person::findPerson (string Firstname, string Lastname, bool &PersonFound) {
    Person* pReturnPerson = nullptr;
    PersonFound = false;

    if ( (Firstname == getFirstName()) && (Lastname == getLastName()) ) {
        pReturnPerson = this;
        PersonFound = true;
        return pReturnPerson;
    } else if (children.empty() == false) {
        for (int i = 0; i<children.size(); i++){
            children[i]->findPerson(Firstname, Lastname, PersonFound);
            if (PersonFound) {
                return children[i];
                break;
            }
        }
    }
    return pReturnPerson;
}


string Person::printPerson() {
    string sReturnString;
    sReturnString = getFirstName() + getLastName() + getGender();
    sReturnString = sReturnString + to_string(getDeathYear()) + to_string(getDeathYear());
    return sReturnString;
}


std::ostream& operator <<(std::ostream& os, const Person& c) {
    os << c.firstname_ << "," << c.lastname_ << "," << c.gender_ << "," << c.birthYear_ << "," << c.deathYear_;
    return os;
}
//static Person parse(const std::string &str) {
//auto v = splitString(str);
//return {v[0], v[1], v[2], std::stoi(v[3]), std::stoi(v[4])};



