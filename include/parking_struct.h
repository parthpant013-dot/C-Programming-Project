#ifndef PARKING_STRUCT_H
#define PARKING_STRUCT_H

#include <time.h>

typedef struct {
    int slot;
    char vehicleNo[20];
    char ticketID[20];
    char type[10];
    int isVIP;
    time_t entryTime;
    int occupied;
} Parking;

#endif
