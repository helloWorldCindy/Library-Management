#include <string>

using namespace std;

#include "Computer.h"

Computer::Computer(string n,float s,int num,bool second,int p)
{
   name=n;
   price=p;
   monitorSize=s;
   modelNumber=num;
   secondHand=second;
}

float Computer::getSize()        {return monitorSize;}
int Computer::getNumber()        {return modelNumber;}
bool Computer::IsItSecondHand()  {return modelNumber;}
