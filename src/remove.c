#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#include "../include/remove.h"
#include "../include/utils.h"

void removeVehicle(Parking *p, int n, double *totalRevenue) {
    char ticket[20], coupon[20];

    printf("Enter Ticket ID: ");
    scanf("%19s", ticket);

    for (int i = 0; i < n; i++) {
        if (p[i].occupied && strcmp(p[i].ticketID, ticket) == 0) {
            time_t exitTime = time(NULL);
            double sec = difftime(exitTime, p[i].entryTime);
            double units = sec / 10.0;
            if (units < 1)
                units = 1;

            double rate = getRate(p[i].type);
            if (p[i].isVIP)
                rate *= 2;

            double bill = units * rate;

            if (sec < 30)
                printf("Stay Category: Short Stay\n");
            else if (sec <= 120)
                printf("Stay Category: Medium Stay\n");
            else
                printf("Stay Category: Long Stay (10%% discount)\n"), bill *= 0.9;

            printf("Apply Coupon? (type NONE for no): ");
            scanf("%19s", coupon);

            for (int j = 0; coupon[j]; j++)
                coupon[j] = toupper(coupon[j]);

            if (strcmp(coupon, "SAVE10") == 0)
                bill *= 0.90;

            *totalRevenue += bill;

            printf("Slot: %d\n", i + 1);
            printf("Time Parked: %.2f sec\n", sec);
            printf("Bill: Rs %.2f\n", bill);
            printf("Total Earnings: Rs %.2f\n", *totalRevenue);

            logToFile(&p[i], sec, bill);

            p[i].occupied = 0;
            p[i].vehicleNo[0] = '\0';
            p[i].ticketID[0] = '\0';
            return;
        }
    }
    printf("Invalid Ticket ID\n");
}
