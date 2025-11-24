#ifndef STATUS_H
#define STATUS_H

#include "parking_struct.h"

// Show parking stats like free, occupied, revenue
void showParkingStatus(Parking *p, int n, double revenue);

// Graphical map (slots in grid view)
void showParkingMap(Parking *p, int n);

#endif
