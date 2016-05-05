#include "Course.h"
#include "BookArray.h"

Course::Course(string s, string nu, string na, string i, int e)
{
  subj  = s;
  num   = nu;
  name  = na;
  instr = i;
  enrol = e;
  books=new BookArray();
}

Course::~Course()
{
  delete books;
}

string Course::getCode()      { return subj + num; }
string Course::getName()      { return name; }
string Course::getInstr()     { return instr; }
int    Course::getEnrol()     { return enrol; }

int    Course::getNumBooks()  { return books->getSize(); }

void   Course::addBook(Book* b)
{
  books->add(b);
}

BookArray* Course::getArray(){ return books; }

string Course::bookArrayString()
{
  string bookInfo;
  if(getNumBooks()==0)
    bookInfo="No books available";
  else
  { 
    for(int i=0;i<getNumBooks();i++)
    {
      string myStrOne,myStrTwo,myStrThree;
      stringstream s,ss,sss;
      s<<books->getBook(i)->getEdition();
      myStrOne=s.str();
      ss<<books->getBook(i)->getYear();
      myStrTwo=ss.str();
      sss<<i;
      myStrThree=sss.str();
      bookInfo+="\nNo. "+myStrThree+"\nName is "+books->getBook(i)->getName()+"\nTitle is "+books->getBook(i)->getTitle()
      +"\nAuthor is "+books->getBook(i)->getAuthors()+"\nISBN is  "
      +books->getBook(i)->getISBN()
      +"\nEdition is "+myStrOne+"\nYear is "+myStrTwo+". \n";
    }
  }
  return bookInfo;
}

bool Course::operator>=(Course* course)
{
  return getCode()>course->getCode();
}

bool Course::operator==(string code)
{
  return code==getCode();
}

bool Course::operator==(Course* course)
{
  return getCode()==course->getCode();
}

string& operator<<(string& str,Course& course)
{
  int enr=course.getEnrol();
  string myStr;
  stringstream ss;
  ss<<enr;
  myStr=ss.str();
  string textBook=course.bookArrayString();
  str="Course Code: "+course.getCode()+"\nCourse Name: "
  +course.getName()+"\nCourse Instructor: "+course.getInstr()
  +"\nCourse Enrolment "+myStr+"\nCourse Textbooks: \n"+textBook+"\n";
  return str;
}
