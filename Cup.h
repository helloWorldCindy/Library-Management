#ifndef CUP_H
#define CUP_H
#include "string.h"
#include "Product.h"

class Cup : public Product                   //The cup class is one of the products available to make by the user in the bookstore.
{
  public:
    Cup(string="",bool=true,int=0,int=0);
    bool IsItGlassOrMug();
    int getHeight();

  private:
    bool glassOrMug;
    int height;
};
#endif
