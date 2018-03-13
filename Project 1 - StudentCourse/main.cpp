// SaeedReza AlipourFard
// 9412032
#include <iostream>
#include <malloc.h>
#include <cstdlib>
#include <conio.h>
#include "StudentCourse.h"

using namespace std;

void menu ();
void addStd (listOfStudent *); // add student to list
void addCour (listOfStudent *); // add course to a student
void remStd (listOfStudent *); // remove student from list
void remCour (listOfStudent *); // remove a course of student
void printAll (const listOfStudent *); // print all of data in list
void printStdAll (const listOfStudent *); // print a student data
void clrscr (); // clear screen for better performance

int main()
{
    listOfStudent lStd; // Main List of Student
    char check;
    do
    {
        clrscr ();
        menu ();
        check = getch ();
        switch (check)
        {
        case '1':
            addStd ( &lStd );
            break;
        case '2':
            addCour ( &lStd );
            break;
        case '3':
            remStd ( &lStd );
            break;
        case '4':
            remCour ( &lStd );
            break;
        case '5':
            printStdAll ( &lStd );
            break;
        case '6':
            printAll ( &lStd );
            break;
        default:
            break;
        }
        if (check == '0')
            break;

    } while ( true );
    clrscr ();
    cout << "Tasks are Finished !!!" << endl;
    lStd.removeAll();
    return 0;
}

void menu ()
{
    clrscr ();
    cout << "Please Enter One of Numbers bellow for your tasks : " << endl;
    cout << "1. To Add a Student to List." << endl;
    cout << "2. To Add a Lesson to One of Students." << endl;
    cout << "3. To Remove a Student from List." << endl;
    cout << "4. To Remove a Lesson from One of the Students." << endl;
    cout << "5. To Print a Student's Data." << endl;
    cout << "6. To Print All of Data in the List." << endl;
    cout << "0. EXIT." << endl;
}

void addStd (listOfStudent *sd)
{
    clrscr ();
    long int d;
    string nm;
    cout << "To Add a Student, Please Enter Following in Order :" << endl;
    cout << "Student Number : " << endl;
    cin >> d;
    cout << "Student's Full Name :" <<endl;
    getline (cin ,nm);
    getline (cin ,nm);
    sd -> addStudent(d ,nm);
    cout << " ======================== " << endl << "Successful Added !!" << endl
    << endl << "Press Any Key to Continue ." << endl;
    getch();
    return;
}

void addCour (listOfStudent *s)
{
    clrscr ();
    long int d;
    int cd ,unt;
    string nm;
    float grd;
    cout << "To Add a Lesson to One Of Student Please Enter Following Data :" << endl;
    cout << "Student's ID :" << endl;
    cin >> d;
    cout << "Lesson's Code :" << endl;
    cin >> cd;
    cout << "Lesson's Name :" << endl;
    getline(cin ,nm);   // Reading \n at end of cin // Trash getline !!!
    getline (cin ,nm);
    cout << "Lesson's Unit :" << endl;
    cin >> unt;
    cout << "Grade of Student in this Lesson :" << endl;
    cin >> grd;
    cout << " ======================== " << endl;
    if (s -> addCourseStd(d ,cd ,nm ,unt ,grd))
        cout << "Successful Added !!" << endl;
    else
        cout << "There is't any Student with this ID !" << endl;
    cout << endl << "Press Any Key to Continue." << endl;
    getch ();
    return;
}

void remStd (listOfStudent *s)
{
    clrscr ();
    long int d;
    cout << "To Remove Student Please Enter ID of Student :" << endl;
    cin >> d;
    cout << " ======================== " << endl;
    if (s -> removeStudent (d))
        cout << "Successful Removed !!" << endl;
    else
        cout << "There is't Any Student with this ID !" << endl;
    cout << endl << "Press Any Key to Continue." << endl;
    getch();
    return;
}

void remCour (listOfStudent *s)
{
    clrscr ();
    long int d;
    int cd;
    cout << "To Remove a Lesson from One of the Students Please Enter Following Data :" << endl;
    cout << "Enter Student's ID :" << endl;
    cin >> d;
    cout << "Enter Code of Lesson :" << endl;
    cin >> cd;
    cout << " ======================== " << endl;
    if (s -> removeCourseStd (d ,cd))
        cout << "Successful Removed !!" << endl;
    else
        cout << "There is't Any Student with this ID \nOr \nThere is't Any course for this Student with this Code !" << endl;
    cout << endl << "Press Any Key to Continue." << endl;
    getch();
    return;
}

void printStdAll (const listOfStudent *s)
{
    clrscr ();
    long int d;
    cout << "Enter Student ID to Print Data :" << endl;
    cin >> d;
    s -> printOneStd (d);
    cout << " ======================== " << endl;
    cout << endl << "Press Any Key to Continue." << endl;
    getch();
    return;
}

void printAll (const listOfStudent *s)
{
    clrscr ();
    cout << "All Of Data in List :\n" << endl;
    s -> travelStudent ();
    cout << " ======================== " << endl;
    cout << endl << "Press Any Key to Continue." << endl;
    getch();
    return;
}

 void clrscr ()
 {
     system ("CLS");
     return;
 }
