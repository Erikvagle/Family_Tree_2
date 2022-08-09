#include "Person.h"

Person::Person(string firstname, string lastname, string gender, string birthYear, string deathYear, Person* Parent):
    firstname_(firstname), lastname_(lastname), gender_(gender), birthYear_(birthYear), deathYear_(deathYear), Parent_(Parent)
{
    // Constructor assigning initial values
    children = vector<Person *>();
}
Person::~Person() {
    if (!children.empty()) {
        for (int i=0; i<children.size(); i++) {
            cout << "Destructor called on " + children[i]->firstname_ << ", " << children[i]->lastname_ << endl;
            delete children[i];
        }
    }
}
/*void Person::traverse(int nIndent){
    //Depth-first-traversal and print
    if (!children.empty()) {
        nIndent = nIndent + 5;
        for (int i = 0; i<children.size(); i++){
            children[i]->traverse(nIndent);
        }
        for (int i=0; i< nIndent;i++) {
            cout << " ";
        }
        cout << firstname_ << "," << lastname_ << "," << gender_ << "," << birthYear_ << "," << deathYear_ << endl;
    }
    else{
        cout << firstname_ << "," << lastname_ << "," << gender_ << "," << birthYear_ << "," << deathYear_ << endl;
    }
}

void Person::breadthFirstTraverse(int nIndent) {
    //breadth-first-traversal and print
    for (int i=0; i< nIndent;i++) {
        cout << " ";
    }
    cout << firstname_ << "," << lastname_ << "," << gender_ << "," << birthYear_ << "," << deathYear_ << endl;
    nIndent = nIndent + 5;
    if (!children.empty()) {
        for (int i = 0; i < children.size(); i++) {
            children[i]->breadthFirstTraverse(nIndent);
        }
    }
}*/

void Person::traverse(int nIndent){
    //Depth-first-traversal and print
    for (int i=0; i< nIndent;i++) {
        cout << " ";
    }
    if (children.empty()) {
        cout << firstname_ << "," << lastname_ << "," << gender_ << "," << birthYear_ << "," << deathYear_ << endl;
    }
    else{
        for (int i = 0; i<children.size(); i++){
            nIndent = nIndent + 5;
            children[i]->traverse(nIndent);
        }
        cout << firstname_ << "," << lastname_ << "," << gender_ << "," << birthYear_ << "," << deathYear_ << endl;
    }
}

void Person::breadthFirstTraverse(int nIndent) {
    //breadth-first-traversal and print
    for (int i=0; i< nIndent;i++) {
        cout << " ";
    }
    cout << firstname_ << "," << lastname_ << "," << gender_ << "," << birthYear_ << "," << deathYear_ << endl;
    nIndent = nIndent + 5;
    if (!children.empty()) {
        for (int i = 0; i < children.size(); i++) {
            children[i]->breadthFirstTraverse(nIndent);
        }
    }
}

/*
void Person::printByGeneration(Person* Tree) {
    vector<Person *> AllChildren = vector<Person *>();
    Person* pCurrentPerson;
    for (int i=0; i < Tree->children.size(); i++){
        pCurrentPerson = Tree->children[i];
        AllChildren.push_back(pCurrentPerson);
        cout << *pCurrentPerson << " || ";
    }

    printByGeneration(AllChildren);
}


void Person::printByGeneration (vector<Person *> &AllChildren) {
    // Find all children
    vector<Person *> NewGeneration = vector<Person *>();
    Person* pCurrentPerson, pCurrentNextGen;

    for (int i=0; i < AllChildren.size(); i++){
        pCurrentPerson = AllChildren[i];

        for (int y=0; y < pCurrentPerson[i].children.size();y++){
            pCurrentNextGen = pCurrentPerson[i].children[y];
            NewGeneration.push_back(*pCurrentNextGen);

        }

        AllChildren.push_back(children[i]);
        cout << children[i] << " || ";
    }

    // Print
    cout << endl;
    // Send all children recursivly
    this->printByGeneration(AllChildren);


}
*/
string Person::getFirstName() {
        return firstname_;
    }

string Person::getLastName() {
        return lastname_;
    }

string Person::getGender() {
        return gender_;
    }

void Person::setParent(Person* newParent){
    Parent_ = newParent;
}

Person* Person::getParent(){
    return Parent_;
}

string Person::getBirthYear() {
        return birthYear_;
    }

string Person::getDeathYear() {
        return deathYear_;
    }

void Person::setFirstName(string FirstName) {
    firstname_ = FirstName;
}
void Person::setLastName(string LastName){
    lastname_ = LastName;
}
void Person::setGender(string Gender) {
    gender_ = Gender;
}
void Person::setBirthYear(string BirthYear) {
    birthYear_ = BirthYear;
}
void Person::setDeathYear(string DeathYear) {
    deathYear_ = DeathYear;
}

void Person::addChild(Person* nextPerson){
    //add existing child to a person
    nextPerson->setParent(this);
    children.push_back(nextPerson);
}
void Person::addChild(string firstname, string lastname, string gender, string birthYear, string deathYear){
    //create and add a new child to person
    Person* newChild = new Person(firstname, lastname, gender, birthYear, deathYear);
    newChild->setParent(this);
    children.push_back(newChild);
}

void Person::findPerson (string Firstname, string Lastname, Person* &pReturnPerson) {
    if ((Firstname == getFirstName()) && (Lastname == getLastName())) {
        pReturnPerson = this;
        return;
    } else if (!children.empty()) {
        for (int i = 0; i<children.size(); i++){
            children[i]->findPerson(Firstname, Lastname, pReturnPerson);
        }
    }
    return;
}

string Person::printPerson() {
    string sReturnString;
    sReturnString = getFirstName() + ", " + getLastName() + ", " + getGender();
    sReturnString = sReturnString + ", " + getBirthYear() + ", " + getDeathYear();
    return sReturnString;
}

void Person::removePerson () {
    Person* pParent = this->getParent();
    if (pParent) {
        // Remove child from parent
        for (int i=0; pParent->children[i]; i++) {
            if (this == pParent->children[i]){
                pParent->children.erase(pParent->children.begin()+i);
                cout << *this << " has been deleted" << endl;
            }
        }
    }
}

void Person::editPerson() {
    // Print values of current person
    string sCurrentFirstName, sCurrentLastName, sCurrentGender, sCurrentBirthYear, sCurrentDeathYear;
    string sNewValue;
    sCurrentFirstName = getFirstName();
    sCurrentLastName = getLastName();
    sCurrentGender = getGender();
    sCurrentBirthYear = getBirthYear();
    sCurrentDeathYear = getDeathYear();

    cout << "Each value will be printed below. Type in new value or just hit enter to keep the old value" << endl;

    cout << "Current first name: " << sCurrentFirstName << endl;
    cout << "Enter new first name: ";
    getline(cin, sNewValue );

    if (sNewValue.size() != 0)
        setFirstName(sNewValue);

    cout << "Current last name: " << sCurrentLastName << endl;
    cout << "Enter new last name: ";
    getline(cin, sNewValue );

    if (sNewValue.size() != 0)
        setLastName(sNewValue);

    cout << "Current gender: " << sCurrentGender << endl;
    cout << "Enter new gender: ";
    getline(cin, sNewValue );

    if (sNewValue.size() != 0)
        setGender(sNewValue);

    cout << "Current birth year: " << sCurrentBirthYear << endl;
    cout << "Enter new birth year: ";
    getline(cin, sNewValue );

    if (sNewValue.size() != 0)
        setBirthYear(sNewValue);

    cout << "Current death year: " << sCurrentDeathYear << endl;
    cout << "Enter new death year: ";
    getline(cin, sNewValue );

    if (sNewValue.size() != 0)
        setDeathYear(sNewValue);

    cout << "Values updated to :" << endl << *this << endl;


}

std::ostream& operator <<(std::ostream& os, const Person& c) {
    os << c.firstname_ << ", " << c.lastname_ << ", " << c.gender_ << ", Born: " << c.birthYear_ << ", Died: " << c.deathYear_;
    return os;
}
//static Person parse(const std::string &str) {
//auto v = splitString(str);
//return {v[0], v[1], v[2], std::stoi(v[3]), std::stoi(v[4])};



