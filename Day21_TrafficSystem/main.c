#include <stdio.h>
#include <math.h>

#define MAX 30

void inputData(int vehicleID[], int speed[], int lane[], int *n);
int countSpeedViolations(int speed[], int n, int *highest, int *lowest);
int countLaneViolations(int vehicleID[], int lane[], int n, int *severeID, int *maxSeverity);
int busiestLane(int laneCount[]);
int leastBusyLane(int laneCount[]);
void displayReport(int vehicleID[], int speed[], int lane[], int n);

int main() {
    int vehicleID[MAX], speed[MAX], lane[MAX], n;
    int highest, lowest, severeID, maxSeverity;
    int laneCount[4] = {0};

    inputData(vehicleID, speed, lane, &n);
    for (int i = 0; i < n; i++)
        laneCount[lane[i] - 1]++;
    int speedVio = countSpeedViolations(speed, n, &highest, &lowest);
    int laneVio = countLaneViolations(vehicleID, lane, n, &severeID, &maxSeverity);

    int busy = busiestLane(laneCount);
    int least = leastBusyLane(laneCount);

    displayReport(vehicleID, speed, lane, n);

    printf("\n---- SUMMARY ----\n");
    printf("Speed Violations: %d\n", speedVio);
    printf("Highest Speed: %d\n", highest);
    printf("Lowest Speed: %d\n", lowest);
    printf("Lane Violations: %d\n", laneVio);
    printf("Most Severe Violation Vehicle ID: %d\n", severeID);
    printf("Busiest Lane: %d\n", busy);
    printf("Least Busy Lane: %d\n", least);
    printf("Total Traffic Volume: %d\n", n);

    return 0;
}

void inputData(int vehicleID[], int speed[], int lane[], int *n) {
    printf("Enter number of vehicles (max 30): ");
    scanf("%d", n);

    for (int i = 0; i < *n; i++) {
        printf("\nVehicle %d ID: ", i + 1);
        scanf("%d", &vehicleID[i]);

        printf("Speed: ");
        scanf("%d", &speed[i]);

        printf("Lane (1-4): ");
        scanf("%d", &lane[i]);
    }
}

int countSpeedViolations(int speed[], int n, int *highest, int *lowest) {
    int count = 0;
    *highest = speed[0];
    *lowest = speed[0];

    for (int i = 0; i < n; i++) {
        if (speed[i] > 80)
            count++;

        if (speed[i] > *highest)
            *highest = speed[i];
        if (speed[i] < *lowest)
            *lowest = speed[i];
    }
    return count;
}

int countLaneViolations(int vehicleID[], int lane[], int n, int *severeID, int *maxSeverity) {
    int count = 0;
    *maxSeverity = -1;

    for (int i = 0; i < n; i++) {
        int expectedLane = vehicleID[i] % 4;
        if (expectedLane == 0) expectedLane = 4;

        if (expectedLane != lane[i]) {
            count++;
            int severity = abs(expectedLane - lane[i]);

            if (severity > *maxSeverity) {
                *maxSeverity = severity;
                *severeID = vehicleID[i];
            }
        }
    }
    return count;
}

int busiestLane(int laneCount[]) {
    int max = laneCount[0], lane = 1;
    for (int i = 1; i < 4; i++) {
        if (laneCount[i] > max) {
            max = laneCount[i];
            lane = i + 1;
        }
    }
    return lane;
}

int leastBusyLane(int laneCount[]) {
    int min = laneCount[0], lane = 1;
    for (int i = 1; i < 4; i++) {
        if (laneCount[i] < min) {
            min = laneCount[i];
            lane = i + 1;
        }
    }
    return lane;
}

void displayReport(int vehicleID[], int speed[], int lane[], int n) {
    printf("\nVehID\tSpeed\tLane\tSpeedVio\tLaneVio\n");
    for (int i = 0; i < n; i++) {
        int speedVio = speed[i] > 80 ? 1 : 0;

        int expected = vehicleID[i] % 4;
        if (expected == 0) expected = 4;
        int laneVio = expected != lane[i];

        printf("%d\t%d\t%d\t%d\t\t%d\n", vehicleID[i], speed[i], lane[i], speedVio, laneVio);
    }
}

