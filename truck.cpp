/* Benjamin Braun
 * CpSc 1070 - Section 2
 * Fall 2018
 * truck.cpp
 *
 * -instantiates Truck objects
 * -setter and getter functions
 *
 */


#include "truck.h"

// default constructor for Truck
// sets default values
Truck::Truck() {
  axles = 0;
  weight = 0.0;
  paymentType = "";
}

// parameterized constructor for Truck
// takes the axle count
// takes the weight
// takes the payment type
// sets the member variables to these values
Truck::Truck(int axles, double grossWt, string paymentType) {
  Truck::axles = axles;
  weight = grossWt;
  Truck::paymentType = paymentType;
}

// returns the number of axles on the Truck
int Truck::getAxles() {
  return axles;
}

// returns the weight of the Truck
double Truck::getWeight() {
  return weight;
}

// returns the payment type used by the Truck
string Truck::getPaymentType() {
  return paymentType;
}

// takes an int ax
// sets the number of axles to ax
void Truck::setAxles(int ax) {
  axles = ax;
}

// takes a double wt
// sets the weight to wt
void Truck::setWeight(double wt) {
  weight = wt;
}

// takes a string pt
// sets the truck's payment type to pt
void Truck::setPaymentType(string pt) {
  paymentType = pt;
}
