#include <iostream>
#include <vector>
#include "PatientAccount.h"

/**
 * TODO: Group Project
20. Patient Fees

2. You are to write a program that computes a patient’s bill for a hospital stay. The different components of the program are
                    The PatientAccount class
                    The Surgery class
                    The Pharmacy class
                    The main program

    – The PatientAccount class will keep a total of the patient’s charges. It will also keep track of the number of days
    spent in the hospital. The group must decide on the hospital’s daily rate.

    – The Surgery class will have stored within it the charges for at least five types of surgery. It can update the
    charges variable of the PatientAccount class.

    – The Pharmacy class will have stored within it the price of at least five types of medication. It can update the
    charges variable of the PatientAccount class.

    – The student who designs the main program will design a menu that allows the user to enter a type of surgery and
    a type of medication, and check the patient out of the hospital. When the patient checks out, the total charges
    should be displayed.
 */

using namespace std;

vector<PatientAccount> patientDataBase;

/**
 * This method allows for a new Patient to be added to the database
 * It asks the user for a name,
 * checks to make sure the patient does not already exist,
 * and then adds it to the data-base
 */
void checkInPatient() {
    string name;

    cout << endl;
    cout << "   Patient Check-in   " << endl;
    cout << "----------------------" << endl;
    cout << "Name: ";
    cin.ignore();
    getline(cin, name);

    for (PatientAccount &i:patientDataBase) {
        if (i.getName() == name) {
            cout << "This patient already exists!";
            return;
        }
    }

    PatientAccount newPatient(name);

    patientDataBase.push_back(newPatient);
    cout << endl;
}

/**
 * Prints out all of the patients that are held in the database
 */
void listPatients() {
    cout << endl;
    for (PatientAccount &i:patientDataBase) {
        cout << i.toString() << endl;
        cout << endl;
    }
}

void workWithPatient() {
    //TODO: finish writing out menu

    string inputName;
    cout << endl;
    cin.ignore();

    cout << "Select a Patient: ";
    getline(cin, inputName);

    for(PatientAccount &i:patientDataBase){
        if(i.getName()==inputName){

            int selection = 0;
            while(selection != 6){
                cout << endl;
                cout << "   Patient Services   " << endl;
                cout << "----------------------" << endl;
                cout << "1. Add Surgery Bill" << endl;
                cout << "2. Add Pharmacy Bill" << endl;
                cout << "3. Add to Days in Hospital" <<endl;
                cout << "4. Print current Info" <<endl;
                cout << "5. Check-out" <<endl;
                cout << "6. Exit Patient menu" <<endl;
                cout << "Selection: ";
                cin >> selection;

                switch (selection){
                    case 1:
                        break;

                }
                return;//done working with patient here, so we leave the method without going through the rest of the list without purpose
            }
        }
    }

    cout << "No patient with that name exists" <<endl;
    cout << endl;
    //select patient to work with
    //give options to choose (surgeries, medications, checkout)
    //perform operation
}

int main() {

    int selection = 0;
    while (selection != 4) {
        cout << "   Hospital Interface   " << endl;
        cout << "------------------------" << endl;
        cout << "1. Patient Check-in" << endl;
        cout << "2. List of Patients" << endl;
        cout << "3. Select Patient" << endl;
        cout << "4. Exit program" << endl;
        cout << "Selection: ";
        cin >> selection;

        switch (selection) {
            case 1:
                checkInPatient();
                break;
            case 2:
                listPatients();
                break;
            case 3:
                workWithPatient();
                break;
            case 4:
                cout << "Good-bye!" << endl;
                return 0;
            default:
                cout << "Invalid selection" << endl;
                break;
        }
    }
    return 0;
}