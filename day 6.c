#include <stdio.h>

int main() {
    float dataUsed, totalBill, baseCost, extraCost = 0, discount = 0;
    int student, corporate;

    printf("Enter total data used (in GB): ");
    scanf("%f", &dataUsed);

    printf("Are you a student? (1 for Yes / 0 for No): ");
    scanf("%d", &student);

    printf("Are you a corporate user? (1 for Yes / 0 for No): ");
    scanf("%d", &corporate);

    printf("\n----- TELECOM BILL SUMMARY -----\n");

    if (dataUsed > 100) {
        printf("Excessive Usage – Plan Not Allowed\n");
    }
    else {
        if (dataUsed < 30) {
            baseCost = 299;
            if (dataUsed > 30)
                extraCost = (dataUsed - 30) * 50;
            totalBill = baseCost + extraCost;
            printf("Selected Plan: Silver\n");
        }
        else if (dataUsed >= 30 && dataUsed <= 60) {
            baseCost = 499;
            if (dataUsed > 60)
                extraCost = (dataUsed - 60) * 40;
            totalBill = baseCost + extraCost;
            printf("Selected Plan: Gold\n");
        }
        else {
            baseCost = 799;
            if (dataUsed > 90)
                extraCost = (dataUsed - 90) * 30;
            totalBill = baseCost + extraCost;
            printf("Selected Plan: Platinum\n");
        }

        if (student == 1 && corporate == 1)
            discount = (15 > 10) ? 15 : 10;
        else if (student == 1)
            discount = 15;
        else if (corporate == 1)
            discount = 10;
        else
            discount = 0;

        totalBill = totalBill - (totalBill * discount / 100);

        printf("Data Used: %.2f GB\n", dataUsed);
        printf("Base Cost: ₹%.2f\n", baseCost);
        printf("Extra Data Cost: ₹%.2f\n", extraCost);
        printf("Discount Applied: %.0f%%\n", discount);
        printf("Total Bill Amount: ₹%.2f\n", totalBill);
    }

    return 0;
}
