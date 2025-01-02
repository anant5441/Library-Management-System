#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <iomanip>
#include <cstring>

class student {
private:
    char admno[10];
    char name[20];
    char stbno[6];
    int token;

public:
    void createstudent();
    void showstudent();
    void modifystudent();
    char* retadmno();
    char* retstbno();
    int rettoken();
    void addtoken();
    void resettoken();
    void getstbno(char t[]);
    void report();
};

#endif

