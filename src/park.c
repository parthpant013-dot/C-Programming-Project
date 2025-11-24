#include <stdio.h>
#include <string.h>
#include <time.h>

#include "../include/park.h"
#include "../include/utils.h"

void parkVehicle(Parking *p, int n) {
    char num[20], type[10];
    int vip;

    printf("Enter Vehicle Number: ");
    scanf("%19s", num);

    if (isAlreadyParked(p, n, num)) {
        printf("Vehicle already parked.\n");
        return;
    }

    printf("Vehicle Type (bike/car/truck): ");
    scanf("%9s", type);

    if (!isValidType(type)) {
        printf("Invalid vehicle type! Only bike, car, truck allowed.\n");
        return;
    }

    printf("VIP Slot? (1=Yes, 0=No): ");
    scanf("%d", &vip);

    for (int i = 0; i < n; i++) {
        if (!p[i].occupied) {
            strcpy(p[i].vehicleNo, num);
            strcpy(p[i].type, type);
            p[i].isVIP = vip;
            p[i].entryTime = time(NULL);
            p[i].occupied = 1;

            generateTicketID(p[i].ticketID, i + 1);

            printf("Vehicle Parked at Slot %d\n", i + 1);
            printf("Ticket ID: %s\n", p[i].ticketID);
            return;
        }
    }

    printf("Parking Full\n");
}
