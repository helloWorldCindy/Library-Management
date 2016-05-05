#ifndef COMPUTER_H
#define COMPUTER_H
#include "string.h"
#include "Product.h"

class Computer : public Product                         //The computer class is one of the products available to make by the user in the bookstore.
{
  public:
    Computer(string="",float=0,int=0,bool=true,int=0);
    float getSize();
    int getNumber();
    bool IsItSecondHand();

  private:
    float monitorSize;
    int modelNumber;
    bool secondHand;
};
#endif
