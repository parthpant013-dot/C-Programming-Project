#ifndef UTILS_H
#define UTILS_H

#include "parking_struct.h"

// Check if a vehicle is already parked
int isAlreadyParked(Parking *p, int n, char *num);

// Generate ticket for a vehicle
void generateTicketID(char *id, int slot);

// Write parking entry/exit information to log file
void logToFile(Parking *v, double sec, double bill);

// Get rate per time unit
double getRate(char *type);

// Check if user entered a valid type: bike/car/truck
int isValidType(char *type);

#endif
