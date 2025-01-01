#include "storybook.h"
#include <iostream>
using namespace std;

void StoryBook::createbook() {
    book::createbook();
    cout << "Enter Genre: ";
    cin.ignore();
    getline(cin, Genre);
    cout << "Enter Type: ";
    getline(cin, Type);
    char choice;
    cout << "Is Issue Allowed (y/n): ";
    cin >> choice;
    IsIssueAllowed = (choice == 'y');
}

void StoryBook::showbook() {
    book::showbook();
    cout << "\nGenre: " << Genre;
    cout << "\nType: " << Type;
    cout << (IsIssueAllowed ? "\nAllowed to Issue" : "\nNot Allowed to Issue");
}

void StoryBook::modifybook() {
    book::modifybook();
    cout << "\nModify Genre: ";
    cin.ignore();
    getline(cin, Genre);
    cout << "Modify Type: ";
    getline(cin, Type);
    char choice;
    cout << "Is Issue Allowed (y/n): ";
    cin >> choice;
    IsIssueAllowed = (choice == 'y');
}
