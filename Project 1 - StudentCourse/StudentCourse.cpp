// SaeedReza AlipourFard
// 9412032
// Defining member Functions of Student and Lesson Class and Lists
#include <iostream>
#include <malloc.h>
#include "StudentCourse.h"

using namespace std;

listOfStudent :: listOfStudent ()
{
    headS = NULL;
}

void listOfStudent :: addStudent (long int &d ,string &nm)
{
    Student *newStd = (Student *)malloc (sizeof (Student));
    newStd -> setStudent (d ,nm ,headS);
    headS = newStd;
}

Student *listOfStudent :: searchStudent (long int &d) const
{
    if (headS == NULL)
        return false;
    if ( headS -> id == d)
        return headS;
    for (Student *p = headS; p -> nextS != NULL; p = p -> nextS)
        if (p -> nextS -> id == d)
            return p;
    return NULL;
}

Student *listOfStudent :: searchExactNodeStudent (long int &d) const
{
    if (headS == NULL)
        return false;
    for (Student *p = headS; p != NULL; p = p -> nextS)
        if ( p -> id == d)
            return p;
    return false;
}

bool listOfStudent :: removeStudent (long int &d)
{
    Student *p = searchStudent ( d );
    if (p == NULL)
        return false;
    Student *delStd;
    if (p == headS)
    {
        delStd = p;
        headS = headS -> nextS;
        free (delStd);
        return true;
    }
    delStd = p -> nextS;
    p -> nextS = p -> nextS -> nextS;
    free (delStd);
    return true;
}

void listOfStudent :: travelStudent () const
{
    if (headS == NULL)
    {
        cout << "List is Empty !!" << endl;
        return;
    }
    for (Student *p  = headS; p != NULL; p = p -> nextS)
    {
        cout << "Student ID : " << p -> id << "\nFull Name : " << p -> fulname
        << "\nAverage of Grades : " << p -> average
        << "\nAll of Courses is  : \n\n";
        p -> courses.travelLesson ();
        cout << " < ---------------- > " << endl;
    }
}

bool listOfStudent :: addCourseStd (long int &d ,int &cd ,string &nm ,int &unt ,float &grd)
{
    Student *p = searchExactNodeStudent (d);
    if ( p == NULL)
        return false;
    p -> courses.addLesson (cd ,nm ,unt ,grd);
    p -> units += unt;
    p -> sumGrades += grd * unt;
    p -> average = (p -> sumGrades) / (p -> units);
    return true;
}

bool listOfStudent :: removeCourseStd (long int &d ,int &cd)
{
    Student *p = searchExactNodeStudent (d);
    if ( p == NULL )
        return false;
    bool b = p -> courses.removeLesson (cd);
    if (b == false)
        return false;
    p -> units = p -> courses.sumOfUnits ();
    p -> sumGrades = p -> courses.sumOfGrades ();
    p -> average = (p -> sumGrades) / (p -> units);
    return true;
}

void listOfStudent :: removeAll ()
{
    Student *p = headS;
    Student *q = (p != NULL ? p -> nextS : NULL);
    for (; p != NULL; p = q ,q = (q != NULL ? q -> nextS : NULL))
    {
        p -> courses.removeAll();
        free (p);
    }
    headS = NULL;
}

void listOfStudent :: printOneStd (long int &d) const
{
    Student *p = searchExactNodeStudent (d);
    if (p == NULL)
        cout << "No Data !!! " << endl;
    else
    {
        cout << "Student ID : " << p -> id << "\nFull Name : " << p -> fulname
        << "\nAverage of Grades : " << p -> average << "\nUnits : " << p -> units
        << "\n\nAll of Courses is  :\n";
        p -> courses.travelLesson ();
    }
}

listOfLesson :: listOfLesson ()
{
    headL = NULL;
}

void listOfLesson :: addLesson (int &cd, string &nm, int &unt ,float &grd)
{
    Lesson *newLes = (Lesson *)malloc ( sizeof (Lesson) );
    newLes -> setLesson (cd ,nm ,unt ,grd ,headL);
    headL = newLes;
}

Lesson * listOfLesson :: searchLesson (int &cd)
{
    if ( headL == NULL)
        return false;
    if ( headL -> code == cd)
        return headL;
    Lesson *p = headL;
    for (; p -> nextL != NULL; p = p -> nextL)
        if (p -> nextL -> code == cd)
            return p;
    return NULL;
}

bool listOfLesson :: removeLesson (int &cd)
{
    Lesson *p = searchLesson (cd);
    if ( p == NULL )
        return false;
    if ( p == headL )
    {
        Lesson *delLes = headL;
        headL = headL -> nextL;
        free (delLes);
        return true;
    }
    Lesson *delLes = p -> nextL;
    p -> nextL = p -> nextL -> nextL;
    free (delLes);
    return true;
}

void listOfLesson :: travelLesson () const
{
    if ( headL == NULL)
    {
        cout << "No Lesson !!! " << endl;
        return;
    }
    int idx = 1;
    for ( Lesson *p = headL; p != NULL; p = p -> nextL ,idx++)
        cout <<"\n" << idx << ". " <<"\nLesson's Code : " << p -> code
        << "\nName of Lesson : " << p -> name
        << "\nLesson's Unit : " << p -> unit << "\nGrade : " << p -> grade << endl
        << " -------------- " << endl;
}

int listOfLesson :: sumOfUnits ()
{
    int ret = 0;
    for ( Lesson *p = headL; p != NULL; p = p -> nextL)
        ret += p -> unit;
    return ret;
}

float listOfLesson :: sumOfGrades ()
{
    float ret = 0;
    for ( Lesson *p = headL; p != NULL; p = p -> nextL)
        ret += ((p -> grade) * (p -> unit));
    return ret;
}

void listOfLesson :: removeAll ()
{
    Lesson *p = headL;
    Lesson *q = (p != NULL ? p -> nextL : NULL);
    for (; p != NULL; p = q ,q = (q != NULL ? q -> nextL : NULL))
        free (p);
    headL = NULL;
}

void listOfLesson :: setHead (Lesson *l)
{
    headL = l;
}

Student :: Student ()
{
    id = 0;
    fulname[0] = '\0';
    average = 0;
    units = 0;
    sumGrades = 0;
    nextS = NULL;
}

void Student :: setStudent (long int &d ,string &fulnm ,Student *ns)
{
    id = d;
    unsigned int i = 0;
    for (; i < fulnm.length(); i++)
        fulname[i] = fulnm[i];
    fulname[i] = '\0';
    courses.setHead (NULL);
    average = 0;
    sumGrades = 0;
    units = 0;
    nextS = ns;
}

void Student :: addCourse (int &cd ,string &nm ,int &unt ,float &grd)
{
    courses.addLesson (cd ,nm ,unt ,grd);
}

void Lesson :: setLesson (int &cd ,string &nm ,int &un ,float &grd ,Lesson *nl)
{
    code = cd;
    unsigned int i = 0;
    for (; i < nm.length(); i++)
        name[i] = nm[i];
    name[i] = '\0';
    unit = un;
    grade = grd;
    nextL = nl;
}
