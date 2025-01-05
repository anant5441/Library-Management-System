#include<iostream>
#include<conio.h>
#include<fstream>
#include<iomanip>
#include<string>
#include<cstring>

using namespace std;

class book
{
    char bno[6];//bookno.
    char bname[50];//bookname
    char aname[20];//authorname
public:
    virtual void createbook()
    {
        cout<<"\nNEW BOOK ENTRY...\n";
        cout<<"\nENTER BOOK NO.";
        cin>>bno;
        if(strlen(bno) > 6 || strlen(bno) < 2)
            throw '1';
        cout<<"\nENTER BOOK NAME"<<endl;
        cin.ignore();
        gets(bname);//enables enter with space
        cout<<"\nENTER AUTHOR NAME";
        gets(aname);
        cout<<"\n\n\nBook Created..";
    }
    virtual void showbook()
    {
        cout<<"\nBook Number: "<<bno;
        cout<<"\nBook Name: ";
        puts(bname);
        cout<<"\nBook Author Name: ";
        puts(aname);
    }
    virtual void modifybook()
    {
        cout<<"\nBook Number: "<<bno;
        cout<<"\nModify Book Name :";
        gets(bname);
        cout<<"\nModify Author's Name :";
        gets(aname);

    }

    char* retbno()//string return
    {
        return bno;

    }
    void report()
    {
        cout<<bno<<setw(30)<<bname<<setw(30)<<aname<<endl;
    }
};

class Textbook : public book
{
private:
    string Academic_Level;
    int NoInStock;
    int NumberOfIssues;
public:
    void createbook() override
    {
        book::createbook();
        cout<<"\nAs it is a text following fields are also required"<<endl;
        cout<<"Enter Academic level i.e. UG , PG , PHD ..etc"<<endl;
        getline(cin,Academic_Level);
        cout<<"Enter Amount in stock"<<endl;
        cin>>NoInStock;
        cout<<"Enter No of issues"<<endl;
        cin>>NumberOfIssues;
    }
    void showbook() override
    {
        book::showbook();
        cout<<"Reccomended for "<<Academic_Level<<"Students"<<endl;
        cout<<"No of books in stock is "<<NoInStock<<endl;
        cout<<"Has "<<NumberOfIssues<<"Issues"<<endl;
    }
    void modifybook() override
    {
        book::modifybook();
        cout<<"\nModify Academic level i.e. UG , PG , PHD ..etc"<<endl;
        getline(cin,Academic_Level);
        cout<<"Modify Amount in stock"<<endl;
        cin>>NoInStock;
        cout<<"Modify No of issues"<<endl;
        cin>>NumberOfIssues;
    }
};


class StoryBook : public book
{
private:
    string Genre;
    string Type;//Novel , shortStory , Biography..etc
    bool IsIssueAllowed;
public:
    void createbook() override
    {
        book::createbook();
        cout<<"Enter Genre  i.e. Drama , Adventure , SelfHelp..etc"<<endl;
        getline(cin,Genre);
        cout<<"Enter Type  i.e. Novel , shortStory , Biography..etc"<<endl;
        getline(cin,Type);
        char choice;
        cout<<"Is Issue allowed y/n";
        cin>>choice;
        if(choice == 'y')
            IsIssueAllowed =true;
        else
            IsIssueAllowed = false;
    }
    void showbook() override
    {
        book::showbook();
        cout<<"Genre is  "<<Genre<<endl;
        cout<<"and is of type "<<Type<<endl;
        if (IsIssueAllowed)
            cout<<"Allowed to issue"<<endl;
        else
            cout<<"Not allowed to issue"<<endl;
    }
    void modifybook() override
    {
        book::modifybook();
        cout<<"Modify Genre  i.e. Drama , Adventure , SelfHelp..etc"<<endl;
        getline(cin,Genre);
        cout<<"Modify Type  i.e. Novel , shortStory , Biography..etc"<<endl;
        getline(cin,Type);
        char choice;
        cout<<"Is Issue allowed y/n";
        cin>>choice;
        if(choice == 'y')
            IsIssueAllowed =true;
        else
            IsIssueAllowed = false;
    }
};
#include <iostream>
#include<cstring>
using namespace std;

class student
{
    char admno[10];//admission no.
    char name[20];
    char stbno[6];// student book no
    int token;//total book of student
public:
    void createstudent()
    {

        cout<<"\nNEW STUDENT ENTRY...\n";
        cout<<"\nEnter The Admission No. ";
        cin>>admno;
        if(strlen(admno) < 8 || strlen(admno) > 10)
            throw '9';
        cout<<"Enter The Student Name "<<endl;
        cin.ignore();
        std::cin.getline(name, 10);
        token=0;
        stbno[0]='\0';
        cout<<"\n\nStudent Record Created...";
    }
    void showstudent()
    {
        cout<<"\nAdmission Number : "<<admno;
        cout<<"\nStudent Name : ";
        puts(name);
        cout<<"\nNo of Book Issued : "<<token;
        if(token==1)
        {
            cout<<"\nBook Number "<<stbno;
        }
    }
    void modifystudent()
    {
        cout<<"\nAdmission No. "<<admno;
        cout<<"\nModify Student Name : ";
        gets(name);
    }
    char* retadmno()
    {
        return admno;
    }
    char* retstbno()
    {
        return stbno;
    }
    int rettoken()
    {
        return token;
    }
    void addtoken()
    {
        token=1;
    }
    void resettoken()
    {
        token=0;
    }
    void getstbno(char t[])
    {
        strcpy(stbno,t);
    }
    void report()
    {
        cout<<"\t"<<admno<<setw(20)<<name<<setw(10)<<token<<endl ;
    }
};//class ends here

#include <iostream>
#include<conio.h>
#include<iomanip>//input-output manipulator
#include<cstring>
#include<fstream>


using namespace std;

fstream fp,fp1;//object
book bk;
book* bookObj;
student st;//student class object

using namespace std;
void writebook()
{
    char ch;
    fp.open("book.dat",ios::out|ios::app);//write and append data
    do{
        cout<<"Enter Book Type\n"
              "\t1)TextBook\n"
              "\t2)StoryBook\n"
              "\t3)General Book"<<endl;
        int choice;
        cin>>choice;
        switch (choice) {
            case 1:
                bookObj = new Textbook;
                break;
            case 2:
                bookObj = new StoryBook;
                break;
            case 3:
                bookObj = new book;
                break;
            default:
                throw '5';
        }
        bk.createbook();
        fp.write((char*)&bk,sizeof(book));//size of class
        cout<<"\n\nDo you want to add more record...(y/n?) ";
        cin>>ch;
    }while(ch=='y'||ch=='Y');
    fp.close();
}

void writestudent()
{
    char ch;
    fp.open("student.dat",ios::out|ios::app);//write and append data
    do{

        st.createstudent();
        fp.write((char*)&st,sizeof(student));//size of class
        cout<<"\n\nDo you want to add more record...(y/n?) ";
        cin>>ch;
    }while(ch=='y'||ch=='Y');
    fp.close();
}
void displayspb(char n[])
{
    cout<<"\nBOOK DETAILS\n";
    int flag=0;//book not found
    fp.open("book.dat",ios::in);//read data
    while(fp.read((char *)&bk,sizeof(book)))
    {
        if(strcmpi(bk.retbno(),n)==0)//not case sensitive
        {
            bk.showbook();
            flag=1;
        }
    }
    fp.close();
    if(flag==0)//book not found
    {
        cout<<"\n\nBook does not exist";

    }
    getch();
}
void displaysps(char n[])
{
    cout<<"\nSTUDENT DETAILS\n";
    int flag=0;//student not found
    fp.open("student.dat", ios::in);//read data
    while(fp.read((char *)&st,sizeof(student)))
    {
        if(strcmpi(st.retadmno(),n)==0)//not case sensitive
        {
            st.showstudent();
            flag=1;
        }
    }
    fp.close();
    if(flag==0)//student not found
    {
        cout<<"\n\nStudent does not exist";

    }
    getch();
}
void modifybook()
{
    char n[6];
    int found=0;//seach book of given data

    cout<<"\n\nMODIFY BOOK RECORD...";
    cout<<"\n\nEnter the book no. ";
    cin>>n;
    fp.open("book.dat",ios::in|ios::out);
    while(fp.read((char*)&bk,sizeof(book)) && found==0)
    {
        if(strcmpi(bk.retbno(),n)==0)
        {
            bk.showbook();
            cout<<"\nEnter the new details book";
            bk.modifybook();
            int pos=-1*sizeof(bk);
            fp.seekp(pos,ios::cur);//back from current position
            fp.write((char *)&bk,sizeof(book));
            cout<<"\n\nRecord Updated";
            found=1;
        }

    }
    fp.close();
    if(found==0)
    {
        cout<<"\n\nRecord Not Found";

    }
    getch();//press key to get out
}
void modifystudent()
{
    char n[6];
    int found=0;//seach book of given data

    cout<<"\n\nMODIFY STUDENT RECORD...";
    cout<<"\n\nEnter the Enrollment no. ";
    cin>>n;
    fp.open("student.dat",ios::in|ios::out);
    while(fp.read((char*)&st,sizeof(student)) && found==0)
    {
        if(strcmpi(st.retadmno(),n)==0)
        {
            st.showstudent();
            cout<<"\nEnter the new details of student";
            st.modifystudent();
            int pos=-1*sizeof(st);
            fp.seekp(pos,ios::cur);//back from current position
            fp.write((char *)&st,sizeof(student));
            cout<<"\n\nRecord Updated";
            found=1;
        }

    }
    fp.close();
    if(found==0)
    {
        cout<<"\n\nRecord Not Found";

    }
    getch();//press key to get out
}

void deletestudent()
{
    char n[6];
    int flag=0;

    cout<<"\n\n\n\tDELETE STUDENT...";
    cout<<"\n\nEnter the Enrollment no> : ";
    cin>>n;
    fp.open("student.dat",ios::in|ios::out);
    fstream fp2;
    fp2.open("temp.dat",ios::out);
    fp.seekg(0,ios::beg);
    while(fp.read((char*)&st,sizeof(student)))
    {
        if(strcmpi(st.retadmno(),n)!=0)
        {
            fp2.write((char*)&st,sizeof(student));
        }
        else{
            flag=1;//student found
        }
    }
    fp2.close();
    fp.close();
    remove("student.dat");
    rename("temp.dat","student.dat");//data after deletion moved to temp
    if(flag==1)
    {
        cout<<"\n\n\tRecord Deleted..";
    }
    else
    {
        cout<<"\n\nRecord not Found";
    }
    getch();
}
void deletebook()
{
    char n[6];//book no.
    int flag=0;

    cout<<"\n\n\n\tDELETE BOOK...";
    cout<<"\n\nEnter the Book no> : ";
    cin>>n;
    fp.open("book.dat",ios::in|ios::out);
    fstream fp2;//New onject
    fp2.open("Temp.dat",ios::out);//temp having data else than that to be deleted
    fp.seekg(0,ios::beg);
    while(fp.read((char*)&bk,sizeof(book)))
    {
        if(strcmpi(bk.retbno(),n)!=0)
        {
            fp2.write((char*)&st,sizeof(book));
        }
        else{
            flag=1;//student found
        }
    }
    fp2.close();
    fp.close();
    remove("book.dat");
    rename("Temp.dat","book.dat");//data after deletion moved to temp
    if(flag==1)
    {
        cout<<"\n\n\tRecord Deleted... ";
    }
    else
    {
        cout<<"\n\nRecord not Found";
    }
    getch();
}
void displayalls()
{

    fp.open("student.dat",ios::in);//read mode
    if(!fp)
    {
        cout<<"File Could Not Be Open";
        getch();
        return;//press any key and return
    }
    cout<<"\n\n\t\tStudent List\n\n";
    cout<<"==================================================================\n";
    cout<<"\tEnrollment No."<<setw(10)<<"Name"<<setw(20)<<"Book Issued\n";
    cout<<"==================================================================\n";
    while(fp.read((char*)&st,sizeof(student)))
    {
        st.report();
    }
    fp.close();
    getch();
}
void displayallb()
{

    fp.open("book.dat",ios::in);//read mode
    if(!fp)
    {
        cout<<"File Could Not Be Open";
        getch();
        return;//press any key and return
    }
    cout<<"\n\n\t\tBook List\n\n";
    cout<<"==================================================================\n";
    cout<<"Book No."<<setw(20)<<"Book Name"<<setw(25)<<"\tBook Author\n";
    cout<<"==================================================================\n";
    while(fp.read((char*)&bk,sizeof(book)))
    {
        bk.report();
    }
    fp.close();
    getch();
}
void bookissue()
{
    char sn[6],bn[6];
    int found=0,flag=0;

    cout<<"\n\nBOOK ISSUE...";
    cout<<"\n\n\tEnter Enrollment no.";
    cin>>sn;
    fp.open("student.dat",ios::in|ios::out);
    fp1.open("book.dat",ios::in|ios::out);
    while(fp.read((char*)&st,sizeof(student))&& found==0)
    {
        if(strcmpi(st.retadmno(),sn)==0)//compare admsn no.
        {
            found=1;
            if(st.rettoken()==0)//if book not issued
            {
                cout<<"\n\n\tEnter The Book No.";
                cin>>bn;
                while(fp1.read((char*)&bk,sizeof(book))&& flag==0)
                {
                    if(strcmpi(bk.retbno(),bn)==0)//compare book no.
                    {
                        flag=1;
                        st.addtoken();
                        st.getstbno(bk.retbno());//pass book no.
                        int pos=-1*sizeof(st);
                        fp.seekg(pos,ios::cur);
                        fp.write((char*)&st,sizeof(student));
                        cout<<"\n\n\tBook Issued Successfully\n\n Please Note The Book Issue Date On Backside Of Your Book And Return Book Within 15 Days, Otherwise Fine Of 10 Rs Per Day";


                    }
                }
                if(flag==0)
                {
                    cout<<"Book No. Does Not Exists";
                }

            }

            else
            {

                cout<<"You Have Not Returned The Last Book";

            }



        }

    }
    if(found==0)
    {
        cout<<"Student Record Not Exists...";

    }
    getch();
    fp.close();
    fp1.close();
}

void bookdeposit()
{
    char sn[6],bn[6];
    int found=0,flag=0,day,fine;

    cout<<"\n\nBOOK DEPOSIT...";
    cout<<"\n\n\tEnter Enrollment no. Of Student";
    cin>>sn;
    fp.open("student.dat",ios::in|ios::out);
    fp1.open("book.dat",ios::in|ios::out);
    while(fp.read((char*)&st,sizeof(student))&& found==0)
    {
        if(strcmpi(st.retadmno(),sn)==0)//compare admsn no.
        {
            found=1;
            if(st.rettoken()==1)//if book issued
            {
                while(fp1.read((char*)&bk,sizeof(book))&& flag==0)
                {
                    if(strcmpi(bk.retbno(),st.retstbno())==0)
                    {
                        flag=1;
                        bk.showbook();
                        cout<<"\n\n Book Deposited In No. Of Days";
                        cin>>day;
                        if(day>15)
                        {
                            fine=(day-15)*1;
                            cout<<"\n\n Fine = "<<fine;
                        }
                        st.resettoken();

                        int pos=-1*sizeof(st);
                        fp.seekg(pos,ios::cur);
                        fp.write((char*)&st,sizeof(student));
                        cout<<"\n\n\tBook Deposited Successfully";


                    }
                }
                if(flag==0)
                {
                    cout<<"Book No. Does Not Exists";
                }

            }

            else
            {

                cout<<"No Book Issued";

            }



        }

    }
    if(found==0)
    {
        cout<<"Student Record Not Exists...";

    }
    getch();
    fp.close();
    fp1.close();
}


void start()
{
    cout<<"==================================================================\n";
    cout<<"\n\n\n\tLIBRARY MANAGEMENT SYSTEM\n\n"<<endl;
    cout<<"==================================================================\n";
    getch();
}
void adminmenu()
{

    int ch2;
    cout<<"\n\n\n\tADMINISTRATOR MENU";
    cout<<"\n\n\n\t1.CREATE STUDENT RECORD";
    cout<<"\n\n\n\t2.DISPLAY ALL STUDENT RECORD";
    cout<<"\n\n\n\t3.DISPLAY SPECIFIC STUDENT RECORD";
    cout<<"\n\n\n\t4.MODIFY STUDENT RECORD";
    cout<<"\n\n\n\t5.DELETE STUDENT RECORD";
    cout<<"\n\n\n\t6.CREATE BOOK";
    cout<<"\n\n\n\t7.DISPLAY ALL BOOKS";
    cout<<"\n\n\n\t8.DISPLAY SPECIFIC BOOK";
    cout<<"\n\n\n\t9.MODIFY BOOK RECORD";
    cout<<"\n\n\n\t10.DELETE BOOK RECORD";
    cout<<"\n\n\n\t11.BACK TO MAIN MENU";
    cout<<"\n\n\n\tPLEASE ENTER YOUR CHOICE(1-11)";
    cin>>ch2;
    switch(ch2)
    {
        case 1: writestudent();
            break;
        case 2: displayalls();
            break;
        case 3: char num[6];

            cout<<"\n\n\t Please enter Enrollment no.";
            cin>>num;
            displaysps(num);
            break;
        case 4: modifystudent();
            break;
        case 5:deletestudent();
            break;
        case 6:writebook();
            break;
        case 7:displayallb();
            break;
        case 8:
        {char num[6];

            cout<<"\n\n\tPlease enter book no.";
            cin>>num;
            displayspb(num);
            break;
        }
        case 9:modifybook();
            break;
        case 10:deletebook();
            break;
        case 11:
            return;
        default:
            cout<<"Invalid choice";
    }
    adminmenu();
}

int main()

{
    char ch;
    start();
    do{
        cout<<"\n\n\n\t MAIN MENU";
        cout<<"\n\n\n\t1 BOOK ISSUE";
        cout<<"\n\n\n\t2 BOOK DEPOSIT";
        cout<<"\n\n\n\t3 ADMINISTRATOR MENU";
        cout<<"\n\n\n\t4 EXIT";
        cout<<"\n\n\n\t PLEASE SELECT YOUR OPTION(1-4)";
        try {
            cin>>ch;
            if(ch >= 'A' && ch <= 'Z')
                throw "Error";
            else if(ch >= 'a' && ch <= 'z')
                throw "Error";
            switch(ch)
            {
                case '1': bookissue();
                    break;
                case '2': bookdeposit();
                    break;
                case '3':
                    adminmenu();
                    break;
                case '4':
                    exit(0);
                default:
                    if(ch > '0' && ch < '9')
                        throw '0';
                    else
                        throw "Error";
            }
        }
        catch (char Error_Code)
        {
            if(Error_Code == '0')
            {
                cerr<<"\n\n\n\tInvalid choice "<<endl;
            }
            if(Error_Code == '1')
            {
                cerr<<"\n\n\n\tInvalid Book number"<<endl;
            }
            if(Error_Code == '5')
            {
                cerr<<"\n\n\n\tInvalid Book Type"<<endl;
            }
            if(Error_Code == '9')
            {
                cerr<<"\n\n\n\tInvalid Enrollment no"<<endl;
            }
        }
        catch (...)
        {
            cerr<<"\n\n\n\tOops look like something is not right\n"
                  "\t\tPlease try again"<<endl;
        }
    }while(ch!=4 );
    return 0;
}
