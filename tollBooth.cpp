/* Benjamin Braun
 * CpSc 1070 - Section 2
 * Fall 2018
 * tollBooth.cpp
 *
 * -Maintains counts of cars and trucks going by the tollbooth
 * -Maintains counts of cash and card payments
 * -Calculates toll price using individual car or truck data
 * -Prints amount paid for each vehicle that goes by
 * -Prints final totals for the day, including:
 *   -number of cars and trucks
 *   -number of payments made with cash and card
 *   -total tolls collected
 *
 */


#include "tollbooth.h"
#include <math.h>

// Tollbooth constructor
// takes an id to print in the title
// takes an output file pointer to print the title to
// sets all count variables to 0
// prints title message
TollBooth::TollBooth(string id, ofstream &out) {
  TollBooth::id = id;
  out<< "TOLL BOOTH SIMULATION - id: "<<id<<endl;
  carCount = 0;
  truckCount = 0;
  cashCount = 0;
  cardCount = 0;
 	totalToll = 0.0;
}

// returns the id of the Tollbooth
string TollBooth::getID() {
  return id;
}

// returns the total tolls collected
double TollBooth::getTotalToll() {
  return totalToll;
}

// takes a Car from which to read data for processing
// takes an output file pointer to print to
// increments car and payment counts as needed
// calculates the car's toll
void TollBooth::arrive(Car c, ofstream &out) {
	int tollPrice;

  carCount++;

	// toll calculation; $3 + $1 for each door
  tollPrice = 3 + c.getDoors();

	// prints the toll amount for the car
  out <<"Car "<<carCount<<"\t\tAmt Due: $"<<tollPrice<<endl;

	// increments card or cash count depending on the car's payment method
  if(c.getPaymentType() == "card") {
    cardCount++;
  }
  else if(c.getPaymentType() == "cash") {
    cashCount++;
  }

	// adds this car's toll to the total toll
  totalToll += tollPrice;
}

// takes a Truck from which to read data for processing
// takes an output file pointer to print to
// increments truck and payment counts as needed
// calculates the truck's toll
void TollBooth::arrive(Truck t, ofstream &out) {
	int truckToll;

  truckCount++;

	// toll calculation; 5 * the number of axles + $1 per 100 lbs (round up)
	// note: for some reason the sample output provided did not follow
	// 			the rules for rounding in some cases. I assumed this was
	//			not intentional.
  truckToll = 5 * t.getAxles() + (int)ceil(t.getWeight()/100.0);

	// prints the toll amount for the truck
  out <<"Truck "<<truckCount<<"\tAmt Due: $"<<truckToll<<endl;

	// increments card or cash count depending on the truck's payment method
	if(t.getPaymentType() == "card") {
    cardCount++;
  }
  else if(t.getPaymentType() == "cash") {
    cashCount++;
  }

	// adds this truck's toll to the total toll
  totalToll += truckToll;
}

// takes an output file pointer to print to
// prints end-of-day totals for the tollbooth
void TollBooth::printTotals(ofstream &out) {
  out <<"End of the Day totalTolls:"<<endl;
  out <<"Number of cars:  \t"<<carCount<<endl;
  out <<"Number of trucks:\t"<<truckCount<<endl;
  out <<"Total tolls collected:\t$"<<totalToll<<endl;
  out <<"Number paid with cash:\t"<<cashCount<<endl;
  out <<"Number paid with credit card:\t"<<cardCount<<endl;
}
