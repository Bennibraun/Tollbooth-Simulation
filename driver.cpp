/* Benjamin Braun
 * CpSc 1070 - Section 2
 * Fall 2018
 * driver.cpp
 *
 * -opens a file to read info from, as specified by command-line args
 * -opens a file to write output to
 * -checks whether the vehicle is a car or a truck
 * -reads in info specific to the vehicle type
 * -uses the info to initialize a car/truck object
 * -sends the new object to the tollbooth for processing
 * -calls tollbooth's print function to print final totals
 *
 */


#include "tollbooth.h"
#include "truck.h"
#include "car.h"
#include <fstream>
#include <assert.h>
#include <string.h>
using namespace std;

// returns 0
// parameters are command-line arguments
int main(int argc, char *argv[]) {
  char vehicle[6];
  char payment[5];
  string vehStr;
  int doors;
  int axles;
  int weight;
  ofstream out;

  // opens the input file to read
  FILE* inFile;
  inFile = fopen(argv[1], "r");
  assert(inFile);

  // opens the output file
  out.open ("dailyTotals.txt");

	// instantiates a Tollbooth, passing in the output file
  TollBooth tollbooth("123", out);

	// loops through each line read from the input file
  while(fscanf(inFile, "%s", vehicle) != EOF) {
    vehStr = vehicle;
    if(vehStr == "car") {
			// reads in car info
      fscanf(inFile, "%d %s", &doors, payment);
			// sends car info to the Car constructor
      Car car1(doors, payment);
			// processes and prints the new Car
      tollbooth.arrive(car1, out);
    }
    else if(vehStr == "truck") {
			// reads in truck info
      fscanf(inFile, "%d %d %s", &axles, &weight, payment);
			// sends truck info to the Truck constructor
      Truck truck1(axles, weight, payment);
			// processes and prints the new Truck
      tollbooth.arrive(truck1, out);
    }
    else {
			// prints if the first string in a line is not "car" or "truck"
      printf("error 1\n");
    }
  }

	// prints final totals and statistics at the end
  tollbooth.printTotals(out);

  return 0;
}
