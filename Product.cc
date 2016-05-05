#include <string>

using namespace std;

#include "Product.h"
#include "defs.h"

Product::Product(string n,int p)
{
   name=n;
   price=p;
}

string Product::getName()  {return name;}
int Product::getPrice()    {return price;}
