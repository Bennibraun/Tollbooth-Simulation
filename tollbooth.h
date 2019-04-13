/* Benjamin Braun
 * CpSc 1070 - Section 2
 * Fall 2018
 * tollbooth.h
 */


#pragma once
#ifndef TOLLBOOTH_H
#define TOLLBOOTH_H

#include "car.h"
#include "truck.h"
#include <string>
#include <fstream>
using namespace std;


class TollBooth {
  public:
    TollBooth(string id, ofstream &out);
    string getID();
    double getTotalToll();
    void arrive(Car c, ofstream &out);
    void arrive(Truck t, ofstream &out);
    void printTotals(ofstream &out);

 private:
   string id;
   int carCount;
   int truckCount;
   double totalToll;
   int cashCount;
   int cardCount;
};

#endif /* TOLLBOOTH_H */
