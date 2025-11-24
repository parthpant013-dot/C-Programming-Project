#include <stdio.h>
#include <string.h>

#include "../include/status.h"

void showParkingStatus(Parking *p, int n, double revenue) {
    int parkedCount = 0, vipCount = 0, emptyCount = 0;

    for (int i = 0; i < n; i++) {
        if (p[i].occupied) {
            parkedCount++;
            if (p[i].isVIP)
                vipCount++;
        } else {
            emptyCount++;
        }
    }

    printf("\n========== PARKING STATUS ==========\n");
    printf("Total Slots: %d\n", n);
    printf("Occupied Slots: %d\n", parkedCount);
    printf("VIP Slots Occupied: %d\n", vipCount);
    printf("Available Slots: %d\n", emptyCount);
    printf("Total Revenue: Rs %.2f\n", revenue);
    printf("====================================\n");
}

void showParkingMap(Parking *p, int n) {
    int columns = 3;
    int rows = (n + columns - 1) / columns;

    printf("\n============= PARKING MAP =============\n\n");

    for (int r = 0; r < rows; r++) {
        printf("    ");
        for (int c = 0; c < columns; c++) {
            int idx = r * columns + c;
            if (idx < n)
                printf("+----------+   ");
            else
                printf("            ");
        }
        printf("\n    ");

        for (int c = 0; c < columns; c++) {
            int idx = r * columns + c;
            if (idx < n)
                printf("| Slot %-3d |   ", idx + 1);
        }
        printf("\n    ");

        for (int c = 0; c < columns; c++) {
            int idx = r * columns + c;
            if (idx < n)
                printf("| %-8s |   ", p[idx].occupied ? p[idx].vehicleNo : "EMPTY");
        }

        printf("\n    ");
        for (int c = 0; c < columns; c++) {
            int idx = r * columns + c;
            if (idx < n)
                printf("+----------+   ");
        }
        printf("\n\n");
    }
    printf("============== END MAP ==============\n");
}
