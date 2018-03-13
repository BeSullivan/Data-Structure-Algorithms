// SaeedReza AlipourFard
// 9412032
// Student and Lesson Class Definitions --- StudentCourse.cpp
#ifndef StudentCourse_H
#define StudentCourse_H
#include <iostream>
using namespace std;

class Lesson // Data of a Lesson --- Node of Linked List
{
    friend class listOfLesson;
public :
    void setLesson (int & ,string & ,int & ,float & ,Lesson *); // set function
private :
    int code;
    char name[40];
    int unit;
    float grade;
    Lesson *nextL;
};
class listOfLesson  // Linked List for Lessons
{
public :
    listOfLesson (); // Make an empty List constructor initializer
    void addLesson (int & ,string & ,int & ,float &); // Add a Lesson to start of List
    bool removeLesson (int &); // Remove a Lesson with code
    Lesson *searchLesson (int &); // Search a Lesson with code
    void travelLesson () const; // Printing All of List's Data
    int sumOfUnits (); // Sum of all unit's of lessons
    float sumOfGrades (); // Sum of grade * unit of each course in list
    void removeAll (); // Remove ALL of list
    void setHead (Lesson *); // set headL
private :
    Lesson *headL;
};
class Student // Data of a Student --- Node of Linked List
{
    friend class listOfStudent;
public:
    Student (); // constructor initializer
    void setStudent (long int & ,string & ,Student *); // set function
    void addCourse (int & ,string & ,int & ,float &); // adding course to courses variable
private:
    long int id;
    char fulname[40];
    Student *nextS;
    float average;
    float sumGrades;
    int units;
    listOfLesson courses;
};
class listOfStudent // Linked List for Students
{
public :
    listOfStudent (); // Make an empty list
    void addStudent (long int & ,string &); // add a Student to start of List
    bool removeStudent (long int &); // remove a Student from List with ID
    Student *searchStudent (long int &) const; // return it's Father Pointer for simple remove
    Student *searchExactNodeStudent (long int &) const; // return it's pointer for simple print
    void travelStudent () const; // Prints All Data in List
    void printOneStd (long int &) const; // Prints a Student Data
    bool addCourseStd (long int & , int &, string & ,int & ,float &); // Add a Course to a Student with ID
    bool removeCourseStd (long int & ,int &); // remove Course with ID and Code
    void removeAll (); // remove ALL of List
private :
    Student *headS;
};
#endif // StudentCourse_H
