#include "student.h"
#include <iostream>
#include <cstring>
using namespace std;

void student::createstudent() {
    cout << "\nNEW STUDENT ENTRY...\n";
    cout << "\nEnter Admission No.: ";
    cin >> admno;
    if (strlen(admno) < 8 || strlen(admno) > 10) throw '9';
    cout << "Enter Student Name: ";
    cin.ignore();
    cin.getline(name, 20);
    token = 0;
    stbno[0] = '\0';
    cout << "\n\nStudent Record Created.";
}

void student::showstudent() {
    cout << "\nAdmission Number: " << admno;
    cout << "\nStudent Name: " << name;
    cout << "\nNumber of Books Issued: " << token;
    if (token == 1) cout << "\nBook Number: " << stbno;
}

void student::modifystudent() {
    cout << "\nModify Student Name: ";
    cin.ignore();
    cin.getline(name, 20);
}

char* student::retadmno() { return admno; }
char* student::retstbno() { return stbno; }
int student::rettoken() { return token; }
void student::addtoken() { token = 1; }
void student::resettoken() { token = 0; }
void student::getstbno(char t[]) { strcpy(stbno, t); }

void student::report() {
    cout << "\t" << admno << setw(20) << name << setw(10) << token << endl;
}
