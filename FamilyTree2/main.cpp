#include <iostream>
#include <string>
#include "Person.h"


using namespace std;

void PrintHelp () { //Function that prints valid commands
    cout << "Please input command, each command has name and a corresponding number." << endl;
    cout << "Valid commands are" << endl;
    cout << "ADD or 1 to add a child to the active person" << endl;
    cout << "CHOOSE ACTIVE PERSON or 2 to select a new active person" << endl;
    cout << "PRINT or 3 to print family in order" << endl;
    cout << "PRINT2 or 4 to print family tree in order " << endl;
    cout << "HELP or 5 to print valid commands" << endl;
    cout << "EXIT or 6 to exit the program" << endl << endl;
}

/*void AddPerson () {
    string Commando, sFirstName, sLastName, sGender, sBirthYear, sDeathYear;

    cout << "First name: ";
    getline(cin, sFirstName);

    cout << "Last name: ";
    getline(cin, sLastName);

    cout << "Gender: ";
    getline(cin, sGender);

    cout << "Year of birth: ";
    getline(cin, sBirthYear);

    cout << "Year of death: ";
    getline(cin, sDeathYear);

    // TODO: Remove later
    cout << endl << "you entered " << endl;
    cout << "First name = " << sFirstName << endl;
    cout << "Last name =  " << sLastName << endl;
    cout << "Gender = " << sGender << endl;
    cout << "Year of birth = " << sBirthYear << endl;
    cout << "Year of death = " << sDeathYear << endl;

    Person NewPerson = Person(sFirstName, sLastName, sGender, sBirthYear, sDeathYear);
}*/


int main(){
    cout << "Family tree" << endl;
    cout << "This is a general tree where with different commands you can create People and add children to a person of your choosing "  << endl;
    cout << "The first step is creating the Root ancestor" << endl;
    // Create the ancestor
    string Commando, sFirstName, sLastName, sGender, sBirthYear, sDeathYear;

    cout << "First name: ";
    getline(cin, sFirstName);

    cout << "Last name: ";
    getline(cin, sLastName);

    cout << "Gender: ";
    getline(cin, sGender);

    cout << "Year of birth: ";
    getline (cin, sBirthYear);

    cout << "Year of death: ";
    getline (cin, sDeathYear);

    // Remove later
    cout << endl << "you entered " << endl;
    cout << "First name = " << sFirstName << endl;
    cout << "Last name =  " << sLastName << endl;
    cout << "Gender = " << sGender << endl;
    cout << "Year of birth = " << sBirthYear << endl;
    cout << "Year of death = " << sDeathYear << endl;

    Person NewPerson = Person(sFirstName, sLastName, sGender, sBirthYear, sDeathYear);

    Person* pFamilyTree = new Person(sFirstName, sLastName,sGender,sBirthYear,sDeathYear);
    Person* pActivePerson = pFamilyTree;

    // Now we have created out tree and the root node - ready to accept command

    cout << "Active person is" << endl;
    cout << pActivePerson->printPerson() << endl << endl;

    PrintHelp();
    string Command;

    while ((Command != "EXIT") && (Command != "6")) {
        cout << "Type HELP or 5 to list valid commands" << endl;
        cout << "Command: ";
        getline(cin, Command);

        // ADD Command
        if ((Command == "ADD") || (Command == "1")) {

            cout << "First name: ";

            getline(cin, sFirstName);

            cout << "Last name: ";
            getline(cin, sLastName);

            cout << "Gender: ";
            getline(cin, sGender);

            cout << "Year of birth: ";
            getline(cin, sBirthYear);

            cout << "Year of death: ";
            getline(cin, sDeathYear);

            cout << endl << "You entered " << endl;
            cout << "First name = " << sFirstName << endl;
            cout << "Last name =  " << sLastName << endl;
            cout << "Gender = " << sGender << endl;
            cout << "Year of birth = " << sBirthYear << endl;
            cout << "Year of death = " << sDeathYear << endl << endl;

            pActivePerson->addChild(sFirstName, sLastName, sGender, sBirthYear, sDeathYear);
            pActivePerson->printPerson();

            // Print Command
        } else if ((Command == "CHOOSE ACTIVE PERSON") || (Command == "2")) {
            string sParentFirstName, sParentLastName;
            cout << "Parent First Name: ";
            cin >> sParentFirstName;
            cout << "Parent Last Name: ";
            cin >> sParentLastName;
            bool bPersonFound = false;
            Person *pNewParent = pFamilyTree->findPerson(sParentFirstName, sParentLastName, bPersonFound);
            if (pNewParent) {
                pActivePerson = pNewParent;
            } else {
                cout << "Parent not found" << endl;
            }

            cout << "Active person is:" << endl;
            cout << *pActivePerson << endl;
        } else if ((Command == "PRINT") || (Command == "3")) {
            cout << "Family tree printed in X order" << endl;
            pFamilyTree->breadthFirstTraverse();

        } else if ((Command == "PRINT2") || (Command == "4")) {
            cout << "Family tree printed in Y order" << endl;
            pFamilyTree->traverse();

            // CHOOSE ACTIVE PERSON command
        } else if ((Command == "HELP") || (Command == "5")) {
            PrintHelp();

        }
    }
    delete pFamilyTree;
    return 0;
}