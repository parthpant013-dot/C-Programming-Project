#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../include/park.h"
#include "../include/remove.h"
#include "../include/status.h"
#include "../include/utils.h"

double totalRevenue = 0;

int main() {
    srand(time(NULL));

    int n, choice;
    printf("Enter number of parking slots: ");
    if (scanf("%d", &n) != 1 || n < 1) {
        printf("Invalid slot number!\n");
        return 1;
    }

    Parking *p = (Parking *)malloc(n * sizeof(Parking));
    for (int i = 0; i < n; i++) {
        p[i].slot = i + 1;
        p[i].occupied = 0;
    }

    while (1) {
        printf("\n1. Park Vehicle\n2. Remove Vehicle\n3. Display Status\n4. Parking Map\n5. Exit\nEnter Choice: ");
        scanf("%d", &choice);

        if (choice == 1)
            parkVehicle(p, n);
        else if (choice == 2)
            removeVehicle(p, n, &totalRevenue);
        else if (choice == 3)
            showParkingStatus(p, n, totalRevenue);
        else if (choice == 4)
            showParkingMap(p, n);
        else if (choice == 5)
            break;
        else
            printf("Invalid Choice\n");
    }

    free(p);
    return 0;
}
