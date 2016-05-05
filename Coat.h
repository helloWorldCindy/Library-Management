#ifndef COAT_H
#define COAT_H
#include "string.h"
#include "Product.h"

class Coat : public Product                   //The coat class is one of the products available to make by the user in the bookstore.
{
  public:
    Coat(string="",string="",string="",string="",int=0);
    string getColor();
    string getGender();
    string getSeason();

  private:
    string color;
    string gender;
    string season;
};
#endif
