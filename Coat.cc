#include <string>

using namespace std;

#include "Coat.h"

Coat::Coat(string n,string c,string g, string s,int p)
{
   name=n;
   price=p;
   color=c;
   gender=g;
   season=s;
}

string Coat::getColor()   {return color;}
string Coat::getGender()  {return gender;}
string Coat::getSeason()  {return season;}
