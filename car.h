/* Benjamin Braun
 * CpSc 1070 - Section 2
 * Fall 2018
 * car.h
 */


#pragma once
#ifndef CAR_H
#define CAR_H

#include <string>
using namespace std;

class Car {
  public:
   Car();
   Car(int numberOfDoors, string paymentType);
   int getDoors();
   string getPaymentType();
   void setPaymentType(string pt);
   void setDoors(int numdoors);

 private:
   int doors;
   string paymentType;
};

#endif /* CAR_H */
