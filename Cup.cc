#include <string>

using namespace std;

#include "Cup.h"

Cup::Cup(string n,bool g, int h,int p)
{
   name=n;
   price=p;
   glassOrMug=g;
   height=h;
}

int Cup::getHeight()        {return height;}
bool Cup::IsItGlassOrMug()  {return glassOrMug;}
