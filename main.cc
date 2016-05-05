/* * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                 */
/*  Program:  Bookstore Management System          */
/*  Author:   Christine Laurendeau                 */
/*  Date:     17-JUN-2015                          */
/*                                                 */
/*  (c) 2015 Christine Laurendeau                  */
/*  All rights reserved.  Distribution and         */
/*  reposting, in part or in whole, without the    */
/*  written consent of the author, is illegal.     */
/*                                                 */
/* * * * * * * * * * * * * * * * * * * * * * * * * */
#include <iostream>

using namespace std;

#include "BMScontrol.h"


int main()
{
  BMScontrol *control=new BMScontrol();
  
  control->launch();
  delete control;
}
