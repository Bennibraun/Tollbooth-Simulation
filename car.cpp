/* Benjamin Braun
 * CpSc 1070 - Section 2
 * Fall 2018
 * car.cpp
 *
 * -instantiates Car objects
 * -setter and getter functions
 *
 */


#include "car.h"

// default constructor for Car
// sets default values
Car::Car() {
  doors = 0;
  paymentType = "";
}

// parameterized constructor for Car
// takes the door count
// takes the payment type
// sets the member variables to these values
Car::Car(int numberOfDoors, string paymentType) {
  doors = numberOfDoors;
  Car::paymentType = paymentType;
}

// returns the number of doors on the car
int Car::getDoors() {
  return doors;
}

// returns the payment type (cash or card)
string Car::getPaymentType() {
  return paymentType;
}

// takes a string pt for payment type
// sets the car's payment type to pt
void Car::setPaymentType(string pt) {
  paymentType = pt;
}

// takes an int numdoors for door count
// sets the car's number of doors to numdoors
void Car::setDoors(int numdoors) {
  doors = numdoors;
}
