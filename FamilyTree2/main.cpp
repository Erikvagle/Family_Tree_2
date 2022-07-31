#include <iostream>
#include <string>
#include "Person.h"


using namespace std;

void AddPerson () {
    string Commando, sFirstName, sLastName, sGender;
    int nBirthYear, nDeathYear;

    cout << "First name: ";
    getline(cin, sFirstName);

    cout << "Last name: ";
    getline(cin, sLastName);

    cout << "Gender: ";
    getline(cin, sGender);

    cout << "Year of birth: ";
    cin >> nBirthYear;

    cout << "Year of death: ";
    cin >> nDeathYear;

    // TODO: Remove later
    cout << endl << "you entered " << endl;
    cout << "First name = " << sFirstName << endl;
    cout << "Last name =  " << sLastName << endl;
    cout << "Gender = " << sGender << endl;
    cout << "Year of birth = " << nBirthYear << endl;
    cout << "Year of death = " << nDeathYear << endl;

    Person NewPerson = Person(sFirstName, sLastName, sGender, nBirthYear, nDeathYear);
    cout << "Skriver ut klasse instance" << endl;
    cout << NewPerson;

}


int main(){
    // Create the ancestor
    string Commando, sFirstName, sLastName, sGender;
    int nBirthYear, nDeathYear;

    cout << "First name: ";
    getline(cin, sFirstName);

    cout << "Last name: ";
    getline(cin, sLastName);

    cout << "Gender: ";
    getline(cin, sGender);

    cout << "Year of birth: ";
    cin >> nBirthYear;

    cout << "Year of death: ";
    cin >> nDeathYear;

    // Remove later
    cout << endl << "you entered " << endl;
    cout << "First name = " << sFirstName << endl;
    cout << "Last name =  " << sLastName << endl;
    cout << "Gender = " << sGender << endl;
    cout << "Year of birth = " << nBirthYear << endl;
    cout << "Year of death = " << nDeathYear << endl;

    Person NewPerson = Person(sFirstName, sLastName, sGender, nBirthYear, nDeathYear);
    cout << "Skriver ut klasse instance" << endl;
    cout << NewPerson;  // TODO: Remove later

    Person* pFamilyTree = new Person(sFirstName, sLastName,sGender,nBirthYear,nDeathYear);
    Person* pActivePerson = pFamilyTree;

    // Now we have created out tree and the root node - ready to accept commands

    // TODO: Lag intro text
    cout << "Family tree" << endl;
    cout << "Active person is" << endl;
    cout << pActivePerson->printPerson() << endl << endl;
    cout << "Please input command. Valid commands are ADD, PRINT, CHOOSE PARENT or EXIT" << endl;

    string Command;

// TODO: sjekk hva kommando det er og kall rett del av koden
    while (Command != "EXIT") {
        cout << "Command: ";

        getline(cin, Command);
//TODO: ADD Child -> active person
        if (Command == "ADD") {

            cout << "First name: ";

            getline(cin, sFirstName);

            cout << "Last name: ";
            getline(cin, sLastName);

            cout << "Gender: ";
            getline(cin, sGender);

            int nBirthYear, nDeathYear;

            cout << "Year of birth: ";
            cin >> nBirthYear;

            cout << "Year of death: ";
            cin >> nDeathYear;

            cout << endl << "you entered " << endl;
            cout << "First name = " << sFirstName << endl;
            cout << "Last name =  " << sLastName << endl;
            cout << "Gender = " << sGender << endl;
            cout << "Year of birth = " << nBirthYear << endl;
            cout << "Year of death = " << nDeathYear << endl;

            pActivePerson->addChild(sFirstName, sLastName, sGender, nBirthYear, nDeathYear);
            pActivePerson->printPerson();

        } else if (Command == "PRINT") {
            pFamilyTree->breadthFirstTraverse();
        } else if (Command == "CHOOSE PARENT") {
            string sParentFirstName, sParentLastName;
            cout << "Parent First Name: ";
            cin >> sParentFirstName;
            cout << "Parent Last Name: ";
            cin >> sParentLastName;
            bool bPersonFound = false;
            Person* pNewParent = pFamilyTree->findPerson(sParentFirstName,sParentLastName,bPersonFound);
            if (pNewParent) {
                pActivePerson = pNewParent;
            } else {
                cout << "Parent not found" << endl;
            }

            cout << "Active person is:" << endl;
            cout << *pActivePerson;




        } else if (Command == "EXIT") {
            return 0;
        }
//TODO: SET active Person
    }
    return 0;

}

/*int main()
{
    Person Geir{"Geir", "Henriksen", "Male", 1900, 1978};
    //Person Erik{"Erik", "Vagle", "Male", 2001, 2150};
    //Fredrik.addChild(&Erik);
    //Fredrik.addChild(&Erik);
    Geir.addChild("Bjørnar", "Henriksen", "Male", 1924, 2002);
    Geir.addChild("Elisabeth", "Henriksen", "Female", 1930, 2014);
    Geir.addChild("Karl", "Henriksen", "Male", 1935, 0);
    Person* Karl = Geir.selectChild("Karl");
    Karl->addChild("Birte", "Pettersen", "Female", 1965, 0);
    Karl->addChild("Ole", "Henriksen", "Male", 1960, 0);
    Karl->addChild("Monica", "Isaksen", "Female", 1968, 0);
    Person* Bjørnar = Geir.selectChild("Bjørnar");
    Bjørnar->addChild("Bengt", "Henrikse", "Male", 1950, 0);
    Person* Elisabeth = Geir.selectChild("Elisabeth");
    Elisabeth->addChild("katrine", "Henriksen", "Female", 1962, 0);
    Elisabeth->addChild("Lasse", "Henriksen", "Male", 1959, 0);

    int i = 0;








    std::cout << "breadtFirstTraversal" << endl;
    Geir.breadthFirstTraverse();
    std::cout << endl << "depthFirstTraversal" << endl;
    Geir.traverse();
    //std::cout << Fredrik << endl;
    //std::cout << Erik << endl;

}*/