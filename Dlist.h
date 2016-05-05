#ifndef DLIST_H
#define DLIST_H
#include <string>
#include <sstream>
#include "Course.h"
#define MAX 60

template <class T>
class Dlist                           //This class is a course collection class where all the courses are added into a linked list.
{
  template <class V>
  friend string& operator<<(string&,Dlist<V>&);
	
  class Node
  {
    friend class Dlist;
      private:
        T data;
     	Node* next;
	Node* prev;
  };
  
  public:
    Dlist();
    ~Dlist();
    void addCourses(T);
    void deleteCourses(T);
    bool find(string,int*);            //Find if the course is in the list
    int getSize();                     //Get the list's size
    void printCourses();               //Print out the course information
    T* copyArray();
    void cleanUp();                    //Clean up memories
    Dlist<T>& operator+=(T );
    Dlist<T>& operator+=(Dlist<T>* );
    Dlist<T>& operator-=(T );
    Dlist<T>& operator-=(Dlist<T>* );
    string printCourseForward();       //Print out course information forward
    string printCourseBackward();      //Print out course information backward
    T getCourse(int);                  //Return the course at that index

  private:
    int size;
    Node* head;
    T* arr;
};

template <class T>                     
Dlist<T>::Dlist() : head(0),size(0){ }

template <class T>
Dlist<T>::~Dlist()
{
  delete arr;
  Node* currNode = head;
  Node* nextNode;

  while (currNode != 0) {
    nextNode = currNode->next;
    delete currNode;
    currNode = nextNode;
  }
}

template <class T>
void Dlist<T>::cleanUp()
{
  Node* currNode=head;
  Node* nextNode;
  while(currNode !=0)
  {
    nextNode = currNode->next;
    delete currNode->data;
    currNode =nextNode;
  }
}

template <class T>
int Dlist<T>::getSize()        { return size; }

template <class T>
T Dlist<T>::getCourse(int index)
{
  Node* currNode=head;
  Node* prevNode=0;
  int count=0;
  while(currNode!=0)
  {
    if(count==index)
      return currNode->data;
    prevNode = currNode;
    currNode = currNode->next;
    count++;
  }
}

template <class T>
void Dlist<T>::addCourses(T course)
{
  Node* currNode;
  Node* prevNode;

  Node* newNode = new Node;
  newNode->data = course;
  newNode->prev=0;
  newNode->next = 0;

  prevNode = 0;
  currNode = head;

  while (currNode != 0) {
    if (*currNode->data>=newNode->data)
      break;
    prevNode = currNode;
    currNode = currNode->next;
  }

  if (prevNode == 0)
    head = newNode;

  else
    prevNode->next = newNode;

  newNode->prev  = prevNode;
  newNode->next = currNode;
  size++;
  if (currNode != 0)
    currNode->prev = newNode;
}

template <class T>
bool Dlist<T>::find(string code,int *i)
{
  int index=0;
  Node* currNode=head;
  Node* prevNode=0;
  while(currNode!=0)
  {
    if(*currNode->data==code)
    {
      *i=index;
      return true;
    }
    index++;
    prevNode=currNode;
    currNode=currNode->next;
  }
  if(currNode==0)
    return false;
}

template <class T>
void Dlist<T>::deleteCourses(T course)
{
  Node* currNode = head;
  Node* prevNode = 0;

  while (currNode != 0) {
    if (*currNode->data == course)
      break;
    prevNode = currNode;
    currNode = currNode->next;
  }


  if (currNode == 0) {
    return;
  }

  if (prevNode == 0) 
    head = currNode->next;

  else
    prevNode->next = currNode->next;

  if (currNode->next != NULL)
    currNode->next->prev = prevNode;

  size--;
  delete currNode->data;
  delete currNode;
}

template <class T>
string Dlist<T>::printCourseForward()
{
  string newStr;
  Node* currNode = head;
  if(currNode==0)
    newStr="No course available";
  else
  {
    while (currNode != 0)
    {
      string str;
      str<<*currNode->data;
      newStr+=str;
      currNode=currNode->next;
    }
  }
  return newStr;
}

template <class T>
string Dlist<T>::printCourseBackward()
{
   string newStr;
   Node* currNode = head;
   if(currNode==0)
   {
     newStr="No course available";
   }
   else
   {
     while(currNode->next!=0)
       currNode=currNode->next;
     while(currNode != 0) 
     {
       string str;
       str<<*currNode->data;
       newStr+=str;
       currNode=currNode->prev;
     }
   }
   return newStr;
}

template <class T>
Dlist<T>& Dlist<T>::operator+=(T course) 
{
  addCourses(course);
  return *this;
}

template <class T>
Dlist<T>& Dlist<T>::operator+=(Dlist<T>* courses) 
{
  Node* currNode=courses->head;
  while(currNode!=0)
  {
    addCourses(currNode->data);
    currNode=currNode->next;  
  }
  return *this;
}

template <class T>
Dlist<T>& Dlist<T>::operator-=(T course) 
{   
  deleteCourses(course);
  return *this;
}

template <class T>
Dlist<T>& Dlist<T>::operator-=(Dlist<T>* courses) 
{
  Node* currNode = courses->head;
  while(currNode!=0)
  {
    *this-=currNode->data;
    currNode=currNode->next;
  }
  return *this;
}

template <class T>
T* Dlist<T>::copyArray() 
{
  arr =new T[MAX];
  Node* currNode = head;
  int i=0;
  while(currNode!=0)
  {
    arr[i]=currNode->data;
    i++;
    currNode=currNode->next;
  }
  return arr;
}

template <class T>
string& operator<<(string& str,Dlist<T>& courses)
{
  str="Print Forward:\n"+courses.printCourseForward()+"\n"+"Print BackWard:\n"+courses.printCourseBackward();
  return str;
}
#endif
