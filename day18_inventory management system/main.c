#include <stdio.h>
#include <string.h>

int main() {
    int productID[10];
    char productName[10][50];
    int quantity[10];
    float price[10];
    int n, i, choice, searchID;
    float totalValue = 0, value[10];
    int highIndex = 0, lowIndex = 0;

    printf("Enter number of products (max 10): ");
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        printf("\nEnter details of product %d:\n", i + 1);
        printf("Product ID: ");
        scanf("%d", &productID[i]);
        printf("Product Name: ");
        scanf("%s", productName[i]);
        printf("Quantity in stock: ");
        scanf("%d", &quantity[i]);
        printf("Price per item: ");
        scanf("%f", &price[i]);
    }
    do {
        printf("\n--- Inventory Management Menu ---\n");
        printf("1. Display all products\n");
        printf("2. Calculate total inventory value\n");
        printf("3. Show highest and lowest value products\n");
        printf("4. Search product by ID\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\n%-10s %-15s %-10s %-10s\n", "ID", "Name", "Quantity", "Price");
                for(i = 0; i < n; i++) {
                    printf("%-10d %-15s %-10d %-10.2f\n", productID[i], productName[i], quantity[i], price[i]);
                }
                break;

            case 2:
                totalValue = 0;
                for(i = 0; i < n; i++) {
                    totalValue += quantity[i] * price[i];
                }
                printf("\nTotal Inventory Value = %.2f\n", totalValue);
                break;

            case 3:
                for(i = 0; i < n; i++) {
                    value[i] = quantity[i] * price[i];
                }
                highIndex = 0;
                lowIndex = 0;
                for(i = 1; i < n; i++) {
                    if(value[i] > value[highIndex])
                        highIndex = i;
                    if(value[i] < value[lowIndex])
                        lowIndex = i;
                }
                printf("\nHighest Value Product: %s (Value = %.2f)\n", productName[highIndex], value[highIndex]);
                printf("Lowest Value Product: %s (Value = %.2f)\n", productName[lowIndex], value[lowIndex]);
                break;

            case 4:
                printf("\nEnter Product ID to search: ");
                scanf("%d", &searchID);
                int found = 0;
                for(i = 0; i < n; i++) {
                    if(productID[i] == searchID) {
                        printf("\nProduct Found:\n");
                        printf("ID: %d\nName: %s\nQuantity: %d\nPrice: %.2f\n",
                               productID[i], productName[i], quantity[i], price[i]);
                        found = 1;
                        break;
                    }
                }
                if(!found)
                    printf("Product not found!\n");
                break;

            case 5:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }
    } while(choice != 5);

    return 0;
}
