#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

#include "defs.h"
#include "BookArray.h"

class Course {                                          //The course class is to create a single course object and is used to help the user in other services
    friend string& operator<<(string&,Course&);         //like sorting textbooks based on a course or adding textbooks to a specific course. 
  public:
    Course(string="", string="", string="", string="", int=0);
    ~Course();
    string  getCode();
    string  getName();
    string  getInstr();
    int     getEnrol();
    int     getNumBooks();
    void    addBook(Book*);          //Add book to this course
    string  bookArrayString();       //Return the string containing book array information
    BookArray* getArray();           //Return the book array
    string printCourseForward();     //Print out course information forward
    string printCourseBackward();    //Print out course information backward
    bool operator>=(Course* );
    bool operator==(string );
    bool operator==(Course* );
  private:
    string    subj;
    string    num;
    string    name;
    string    instr;
    int       enrol;
    BookArray *books;
};
#endif
