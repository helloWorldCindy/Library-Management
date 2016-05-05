#include <iostream>
using namespace std;
#include <string>
#define MAX 60
#include "Dlist.h"
#include "Course.h"

class MoreServices                         //This class is where all the extra services works. MoreServices is an abstract class and the rest are concrete classes
{                                          //which extends from the abstract class and also inherits the generic function from the abstract class.
  public:
    MoreServices(Dlist<Course*>* l)  {list=l;courses=list->copyArray();}
    virtual ~MoreServices()
    {
      for(int i=0;i<list->getSize();i++)
        delete courses[i];
      delete [] courses;
    }
    virtual void services(string firstParam,string* secondParam) = 0;

  protected:
    Dlist<Course*> *list;
    Course** courses;
};

class FindCourseByInstructor:public MoreServices
{
  public:
    FindCourseByInstructor(Dlist<Course*>* l) : MoreServices(l) { }
    virtual void services(string inst,string* response)
    {
      int i=0;
      bool found=false;
      string str="";
      if(list->getSize()==0)
        *response="No courses available";
      else
      {
        for(i=0;i<list->getSize();i++)
        {
          if(courses[i]->getInstr()==inst)
          {
            str=courses[i]->getCode();
            *response=str;
            found=true;
            break;
          }
        }
        if(found==false)
          *response="Course not found";
      }
    }
};

class SortBooks:public MoreServices
{
  public:
    SortBooks(Dlist<Course*>* l) : MoreServices(l) { }
    virtual ~SortBooks()
    {
      for(int i=0;i<list->getSize();i++)
        delete courses[i];
      delete [] courses;
      delete [] books;
    }
    virtual void services(string code,string* sortedBooksList)
    {
      int i;
      books=new Book[MAX];
      int count=0;
      if(list->getSize()==0)
        *sortedBooksList ="No courses available";
      else
      {
        bool a=false;
        for(i=0;i<list->getSize();i++)
        {
          if(courses[i]->getCode()==code)
          {
            a=true;
            if(courses[i]->getArray()->getSize()==0)
              *sortedBooksList="No books availble";
            else
            {
              string str="";
              for(int j=0;j<courses[i]->getArray()->getSize();j++)
              {
                books[j]=*courses[i]->getArray()->getBook(j);
                count++;
              }
              bool swapped = true;
              int j = 0;
              Book tmp;
              while (swapped)
              {
                swapped = false;
                j++;
                for (int m = 0; m < courses[i]->getArray()->getSize() - j; m++)
                {
                  if (books[m].getName() > books[m+1].getName()) 
                  {
                    tmp = books[m];
                    books[m] = books[m+1];
                    books[m+1] = tmp;
                    swapped = true;
                  }
                }
              }
              for(int n=0;n<courses[i]->getArray()->getSize();n++)
              {
                string myStrOne,myStrTwo,myStrThree;
                stringstream s,ss,sss;
                s<<books[n].getEdition();
                myStrOne=s.str();
                ss<<books[n].getYear();
                myStrTwo=ss.str();
                str+="\nName is "+books[n].getName()+"\nTitle is "+books[n].getTitle()
                +"\nAuthor is "+books[n].getAuthors()+"\nISBN is  "
                +books[n].getISBN()
                +"\nEdition is "+myStrOne+"\nYear is "+myStrTwo+". \n";
              }
              *sortedBooksList=str;
            }
          }
        }
        if(a==false)
          *sortedBooksList="Course not found";
    }
    delete [] books;
  }
  private:
    Book* books;
};

class LoanBooks:public MoreServices
{
  public:
    LoanBooks(Dlist<Course*>* l) : MoreServices(l) { }
     virtual void services(string name,string* result)
     {
       int i;
       bool a = false;
       if(list->getSize()!=0)
       {
         for(i=0;i<list->getSize();i++)
         {
           for(int j=0;j<courses[i]->getArray()->getSize();j++)
           {
             if(courses[i]->getArray()->getBook(j)->getName()==name)
             {
               a = true;
               if(courses[i]->getArray()->getBook(j)->isItBorrowed()==false)
               {
                 *result = "Here is " +name +", please return it in 90 days.";
                 courses[i]->getArray()->getBook(j)->setBorrowed(true);
               }
               else
                 *result="Sorry, " + name + " is aleady on loan.";
             }
           }
         }
         if(a==false)
           *result= "Book not found";
       }
       else
         *result = "No courses available";
     }
};
  
class BooksAvailable:public MoreServices
{
  public:
    BooksAvailable(Dlist<Course*>* l) : MoreServices(l) { }
    virtual void services(string code,string* response)
    {
      int i=0;
      bool found=false;
      int count=0;
      string str="These are the books that are available";
      if(list->getSize()==0)
        *response="No courses available";
      else
      {
        for(i=0;i<list->getSize();i++)
        {
          if(courses[i]->getCode()==code)
          {
            found=true;
            for(int j=0;j<courses[i]->getArray()->getSize();j++)
            {
              if(courses[i]->getArray()->getBook(j)->isItBorrowed()==false)
              {
                count++;
                str = str+"\n<< "+courses[i]->getArray()->getBook(j)->getName()+" >> ";
              }
            }
          }
        }
        if(found==false)
          *response="Course not found";
        else if(count==0)
          *response="All books are on loan";
        else if((found!=false)&&(count!=0))
          *response=str;
      }
    }
};
