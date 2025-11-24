#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../include/utils.h"

int isAlreadyParked(Parking *p, int n, char *num) {
    for (int i = 0; i < n; i++)
        if (p[i].occupied && strcmp(p[i].vehicleNo, num) == 0)
            return 1;
    return 0;
}

void generateTicketID(char *id, int slot) {
    sprintf(id, "TKT%04d%02d", rand() % 9000 + 1000, slot);
}

void logToFile(Parking *v, double sec, double bill) {
    FILE *f = fopen("parking_log.txt", "a");
    if (!f) {
        printf("Error: Unable to open parking_log.txt\n");
        return;
    }

    char entry[30], exitT[30];
    struct tm *en = localtime(&v->entryTime);
    time_t ex = time(NULL);
    struct tm *exx = localtime(&ex);

    strftime(entry, 30, "%Y-%m-%d %H:%M:%S", en);
    strftime(exitT, 30, "%Y-%m-%d %H:%M:%S", exx);

    fprintf(f,
            "Ticket: %s\nVehicle: %s\nType: %s\nSlot: %d\nVIP: %d\nEntry: %s\nExit: %s\nTime: %.2f sec\nBill: %.2f\n\n",
            v->ticketID, v->vehicleNo, v->type, v->slot, v->isVIP, entry, exitT, sec, bill);

    fclose(f);
}

double getRate(char *type) {
    if (strcmp(type, "bike") == 0)
        return 2;
    if (strcmp(type, "car") == 0)
        return 3;
    if (strcmp(type, "truck") == 0)
        return 5;
    return 2;
}

int isValidType(char *type) {
    return strcmp(type, "bike") == 0 || strcmp(type, "car") == 0 || strcmp(type, "truck") == 0;
}
