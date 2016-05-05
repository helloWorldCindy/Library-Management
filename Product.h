#ifndef PRODUCT_H
#define PRODUCT_H
#include "string.h"

class Product                        //The product class is the base class for all the products available in the bookstore.
{
  public:
    Product(string="",int=0);
    string getName();
    int getPrice();
  
  protected:
    string name;
    int price;
};
#endif
