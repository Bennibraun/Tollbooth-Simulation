/* Benjamin Braun
 * CpSc 1070 - Section 2
 * Fall 2018
 * truck.h
 */


#pragma once
#ifndef TRUCK_H
#define TRUCK_H

#include <string>
using namespace std;


class Truck {
  public:
   Truck();
   Truck(int axles, double grossWt, string paymentType );
   int getAxles();
   double getWeight();
   string getPaymentType();
   void setAxles(int ax);
   void setWeight(double wt);
   void setPaymentType(string pt);

  private:
   int axles;
   double weight;
   string paymentType;

};

#endif /* TRUCK_H */
