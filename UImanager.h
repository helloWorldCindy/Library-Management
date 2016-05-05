#ifndef UIMANAGER_H
#define UIMANAGER_H

#include "Dlist.h"
#include "string.h"
#include "Product.h"                                       //The UImanager class is dedicated to the aquiring of information from the user. 
#include "Computer.h"
#include "Cup.h"
#include "Coat.h"
#define TEST_MODE

class UImanager {
  public:
    void mainMenu(int*);                                   //Show the main menu
    void getCourseData(Course**);                          //Get the course data
    void printCourses(Dlist<Course*>*);
    void pause();
    bool addTextBook(Dlist<Course*>*,Book**);              //Add text book to the course
    void listCourses(Dlist<Course*>*);                     //Print out the course information
    void listTextBook(Dlist<Course*>*);                    //Print out the text book information
    void ask(int* );                                       //Ask for operate for one course or several courses
    void deleteInfo(int );                                 //For showing the delete information
    string askNewStuff(int*);                              //Ask the user what he want to buy
    void askAboutComputer(float* ,int* ,bool*,int* );      //Ask user to enter computer's information
    void askAboutCoat(string*,string*,string*,int*);       //Ask user to enter coat's information
    void askAboutCup(int*,bool*,int*);                     //Ask user to enter cup's information
    void printInventory(Product** ,int);                   //Print out the inventory
    void chooseServing(int* );
    void askNameAndSize(string* ,string* );
    void outPutResult(string);
    string severalCourses(int);                            //Return the string add or delete
    string getCourseCode();                                //Return the course code
    string askInfo(int);

  private:
    int getInt();
    string getCode();
};

void UImanager::mainMenu(int* choice)
{
  string str;

  *choice = -1;

  cout << endl << endl << "WELCOME TO THE BOOKSTORE MANAGEMENT SYSTEM" << endl<<endl;
  cout << "  Course Management:" << endl;
  cout << "  ( 1 )  Add course" << endl;
  cout << "  ( 2 )  List all courses" << endl << endl;
  cout << "  Textbook Management:" << endl;
  cout << "  ( 3 )  Add textbook" << endl;
  cout << "  ( 4 )  List course textbooks" << endl;
  cout << "  ( 5 )  Delete a course" << endl << endl;
  cout << "  ( 6 )  Make your product" << endl << endl;
  cout << "  ( 7 )  See products for sale"<<endl<<endl;
  cout << "  ( 8 )  More services"<<endl<<endl;
  cout << "  ( 0 )  Exit" << endl << endl;

  while (*choice < 0 || *choice > 8) {
    cout << "Enter your selection:  ";
    *choice = getInt();
  }
}

void UImanager::getCourseData(Course** course)
{
  string    str = "";
  string    subj, num, name, inst;
  int       enrol;

  cout << endl;

  while (str.length() != 8) {
    cout << "Enter course code (e.g. COMP2404):  ";
    getline(cin, str);
  }
  subj = str.substr(0,4);
  num  = str.substr(4);

  cout << endl << "Enter course name (e.g. Introduction to SE):  ";
  getline(cin, name);

  cout << endl << "Enter instructor name:   ";
  getline(cin, inst);

  cout << endl << "Enter enrolment:   ";
  getline(cin, str);
  stringstream ss(str);
  ss >> enrol;

  Course *tmpCourse=new Course(subj, num, name, inst, enrol);

  *course = tmpCourse;
}

bool UImanager::addTextBook(Dlist<Course*> *list,Book** newBook)
{
  
  string    name;
  string    author;
  string    title;
  string    isbn;
  string    yearStr;
  string    editionStr;
  string    priceStr;
  int       year;
  int       edition;
  int       pos;
  int       price;

  if(list->find(getCode(),&pos))
  {
    cout<<"Enter the name: "<<endl;
    getline(cin,name);
    cout<<"Enter the title: "<<endl;
    getline(cin,title);
    cout<<"Enter the author's name: "<<endl;
    getline(cin,author);
    cout<<"Enter the book's ISBN: "<<endl;
    getline(cin,isbn);
    cout<<"Enter the year: "<<endl;
    getline(cin,yearStr);
    stringstream yearInt(yearStr);
    yearInt >> year;
    cout<<"Enter the edition"<<endl;
    getline(cin,editionStr);
    stringstream ediInt(editionStr);
    ediInt >> edition;
    cout<<"Enter the price"<<endl;
    getline(cin,priceStr);
    stringstream prInt(priceStr);
    prInt >> price;
    *newBook=new Book(name,title,author,isbn,edition,year,price);
    list->getCourse(pos)->addBook(*newBook);
    return true;
  }
  else
  {
    cout<<"This course does not exist"<<endl;
    return false;
  }
}

string UImanager::severalCourses(int which)
{
  string str="";
  if(which==1)
    cout<<"Do you want to add a course?( yes or no )"<<endl;
  else
    cout<<"Do you want to delete a course?( yes or no )"<<endl;
  getline(cin,str);
  return str;
  
}

void UImanager::listCourses(Dlist<Course*>* list)
{
  string str;
  str<<*list;
  cout<<str;
}

void UImanager::listTextBook(Dlist<Course*>* list)
{
  int pos;
  if(list->find(getCode(),&pos))
    cout<<list->getCourse(pos)->bookArrayString()<<endl;
  else
    cout<<"Course Not Found"<<endl;
}

void UImanager::deleteInfo(int status)
{
  if(status==1)
    cout<<"Course is now deleted"<<endl;
  else if(status==2)
    cout<<"Course Not Found"<<endl;
  else
    cout<<"Courses are all deleted."<<endl;
}

string UImanager::getCourseCode()
{
  string str=getCode();
  return str;
}

string UImanager::getCode()
{
  string str="";
  while (str.length() != 8) {
    cout << "Enter course code (e.g. COMP2404):  "<<endl;
    getline(cin, str);
   }
  return str;
}

void UImanager::pause()
{
  string str;

  cout << endl << "\nPress enter to continue...";
  getline(cin, str);
}

int UImanager::getInt()
{
  string str;
  int    num;

  getline(cin, str);
  stringstream ss(str);
  ss >> num;

  return num;
}

void UImanager::ask(int* choice)
{
  *choice = -1;
  cout<<"An individual course or several courses at once (enter 1 for individual, 2 for several)?"<<endl;
  *choice = getInt();
}

string UImanager::askNewStuff(int* choice)
{
  cout<<"What do you want to make?"<<endl;
  cout<<" 1. Computer"<<endl;
  cout<<" 2. Coat"<<endl;
  cout<<" 3. Cup"<<endl;
  while (*choice < 0 || *choice > 3) {
    cout << endl<<"Enter your choice:  ";
    *choice = getInt();
    }
  string name;
  cout<<"What is the product name?"<<endl;
  getline(cin,name);
  return name;
}

void UImanager::askAboutComputer(float* size,int* number,bool* second,int* price)
{
  string sizeStr;
  string modelNumber;
  string secondHandStr;
  string answer;
  string priceStr;
  cout<<"Enter the price"<<endl;
  getline(cin,priceStr);
  stringstream prInt(priceStr);
  prInt >> *price;
  cout<<endl<<"What is the monitor size?";
  getline(cin,sizeStr);
  stringstream sizeFloat(sizeStr);
  sizeFloat >> *size;
  cout<<endl<<"What is the model number?";
  getline(cin,modelNumber);
  stringstream numberS(modelNumber);
  numberS >> *number;
  cout<<endl<<"Is it second hand?(yes or no)";
  getline(cin,answer);
  if(answer=="yes")
    *second=true;
  else
    *second=false;
}

void UImanager::askAboutCoat(string* color,string* gender,string* season,int* price)
{
  string priceStr;
  cout<<"Enter the price"<<endl;
  getline(cin,priceStr);
  stringstream prInt(priceStr);
  prInt >> *price;
  cout<<endl<<"What is the color?";
  getline(cin,*color);
  cout<<endl<<"what is your gender?";
  getline(cin,*gender);
  cout<<endl<<"What is the season?";
  getline(cin,*season);
}

void UImanager::askAboutCup(int* height,bool* itIs,int* price)
{
  string heightStr;
  string mug;
  string priceStr;
  cout<<"Enter the price"<<endl;
  getline(cin,priceStr);
  stringstream prInt(priceStr);
  prInt >> *price;
  cout<<endl<<"Is it a glass or a mug?";
  getline(cin,mug);
  if(mug=="mug")
    *itIs=true;
  else
    *itIs=false;
  cout<<endl<<"What is its height?";
  getline(cin,heightStr);
  stringstream heightS(heightStr);
  heightS >> *height;
}

void UImanager::printInventory(Product** arr,int size)
{
  cout<<"All the products for sale:"<<endl;
  cout<<"-------------------------"<<endl;
  for(int i=0;i<size;i++)
  {
    cout<<i+1<<endl;
    cout<<"Name is :"<<arr[i]->getName()<<endl;
    cout<<"Price is "<<arr[i]->getPrice()<<endl;
  }
}

void UImanager::chooseServing(int* choose)
{
  *choose=-1;
  cout<<"How Can I Help You ?"<<endl<<endl;
  cout<<"1. I want to Find a Course Code For a instructor"<<endl;
  cout<<"2. I want to Sort Books in Course"<<endl;
  cout<<"3. I want to Borrow A Book"<<endl;
  cout<<"4. I want to see which books are not yet being borrowed."<<endl;

  while (*choose < 1 || *choose > 4) {
    cout << "Enter your selection:  ";
    *choose = getInt();
  }
}

string UImanager::askInfo(int choose)
{
  string str;
  if(choose==1)
    cout<<"What is the Instructor's name you want to find?"<<endl;
  if(choose==2)
    cout<<"Which course's books you want to sort by the name in alphabetic order?"<<endl;
  if(choose==3)
    cout<<"What is the name of the book you want to borrow?"<<endl;
  if(choose==4)
    cout<<"What is the course code you want to check?"<<endl;

  getline(cin,str);
  return str;
}

void UImanager::outPutResult(string str)
{  
  cout<<str<<endl;
}
#endif
