#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <iomanip>
#include <cstring>

class book {
protected:
    char bno[6];
    char bname[50];
    char aname[20];

public:
    virtual void createbook();
    virtual void showbook();
    virtual void modifybook();
    char* retbno();
    void report();
    virtual ~book() {}
};

#endif
