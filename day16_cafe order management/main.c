#include <stdio.h>

int main() {
    int prices[5] = {50, 30, 80, 120, 60};
    char items[5][10] = {"Coffee", "Tea", "Sandwich", "Burger", "Pastry"};
    int qty[5] = {0};
    int n, i, j, itemNo, quantity;
    int totalRevenue = 0, totalItems = 0;

    printf(" Café Order Management System \n");
    printf("Menu:\n");
    for (i = 0; i < 5; i++)
        printf("%d. %s - ₹%d\n", i + 1, items[i], prices[i]);

    printf("\nEnter total number of customers (max 10): ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        int numItems, bill = 0;
        printf("\n Customer %d \n", i + 1);
        printf("Enter number of items: ");
        scanf("%d", &numItems);
        for (j = 0; j < numItems; j++) {
            printf("Enter item number and quantity: ");
            scanf("%d %d", &itemNo, &quantity);
            bill += prices[itemNo - 1] * quantity;
            qty[itemNo - 1] += quantity;
        }
        totalRevenue += bill;
        totalItems += numItems;
        printf("Total Bill for Customer %d: ₹%d\n", i + 1, bill);
    }

    // Find most and least ordered items
    int mostIdx = 0, leastIdx = 0;
    for (i = 1; i < 5; i++) {
        if (qty[i] > qty[mostIdx]) mostIdx = i;
        if (qty[i] < qty[leastIdx]) leastIdx = i;
    }

    printf("\n Café Summary \n");
    printf("Total Revenue: ₹%d\n", totalRevenue);
    printf("Total Items Sold: %d\n", totalItems);
    printf("Most Ordered Item: %s\n", items[mostIdx]);
    printf("Least Ordered Item: %s\n", items[leastIdx]);
    return 0;
}

