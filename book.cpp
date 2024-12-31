#include "book.h"
#include <iostream>
#include <cstring>
using namespace std;

void book::createbook() {
    cout << "\nNEW BOOK ENTRY...\n";
    cout << "\nENTER BOOK NO.: ";
    cin >> bno;
    if (strlen(bno) > 6 || strlen(bno) < 2) throw '1';
    cout << "\nENTER BOOK NAME: ";
    cin.ignore();
    cin.getline(bname, 50);
    cout << "\nENTER AUTHOR NAME: ";
    cin.getline(aname, 20);
    cout << "\n\nBook Created.\n";
}

void book::showbook() {
    cout << "\nBook Number: " << bno;
    cout << "\nBook Name: " << bname;
    cout << "\nAuthor Name: " << aname;
}

void book::modifybook() {
    cout << "\nModify Book Name: ";
    cin.ignore();
    cin.getline(bname, 50);
    cout << "\nModify Author's Name: ";
    cin.getline(aname, 20);
}

char* book::retbno() { return bno; }

void book::report() {
    cout << bno << setw(30) << bname << setw(30) << aname << endl;
}
