#include <stdio.h>
#define MAX 20
int productID[MAX];
int quantity[MAX];
int price[MAX];
int count = 0;
void addProduct();
void searchProduct();
void updateQuantity();
void rackReport();
void stockValueReport();
void displayProducts();
int findProductIndex(int id);
int main() {
    int choice;

    while (1) {
        printf("\n  SMART WAREHOUSE MENU \n");
        printf("1. Add Product\n");
        printf("2. Search Product\n");
        printf("3. Update Quantity\n");
        printf("4. Generate Rack Report\n");
        printf("5. Calculate Stock Value Report\n");
        printf("6. Display All Products\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addProduct(); break;
            case 2: searchProduct(); break;
            case 3: updateQuantity(); break;
            case 4: rackReport(); break;
            case 5: stockValueReport(); break;
            case 6: displayProducts(); break;
            case 7: return 0;
            default: printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
int findProductIndex(int id) {
    for (int i = 0; i < count; i++) {
        if (productID[i] == id)
            return i;
    }
    return -1;
}
void addProduct() {
    if (count >= MAX) {
        printf("Warehouse full!\n");
        return;
    }

    int id, qty, pr;
    printf("Enter Product ID: ");
    scanf("%d", &id);

    if (findProductIndex(id) != -1) {
        printf("Duplicate ID not allowed!\n");
        return;
    }

    printf("Enter Quantity: ");
    scanf("%d", &qty);
    printf("Enter Price: ");
    scanf("%d", &pr);

    if (qty <= 0 || pr <= 0) {
        printf("Invalid input! Quantity and Price must be positive.\n");
        return;
    }

    productID[count] = id;
    quantity[count] = qty;
    price[count] = pr;
    count++;

    printf("Product Added Successfully!\n");
}
void searchProduct() {
    int id;
    printf("Enter Product ID: ");
    scanf("%d", &id);

    int index = findProductIndex(id);
    if (index == -1) {
        printf("Product Not Found!\n");
    } else {
        printf("Product Found:\nID: %d\nQuantity: %d\nPrice: %d\n",
               productID[index], quantity[index], price[index]);
    }
}
void updateQuantity() {
    int id, choice, amt;

    printf("Enter Product ID: ");
    scanf("%d", &id);
    int index = findProductIndex(id);

    if (index == -1) {
        printf("Product Not Found!\n");
        return;
    }

    printf("1. Increase Quantity\n2. Decrease Quantity\nEnter choice: ");
    scanf("%d", &choice);

    printf("Enter amount: ");
    scanf("%d", &amt);

    if (choice == 1) {
        quantity[index] += amt;
        printf("Stock Updated!\n");
    }
    else if (choice == 2) {
        if (quantity[index] - amt < 0) {
            printf("Error: Quantity cannot be negative!\n");
            return;
        }
        quantity[index] -= amt;
        printf("Stock Updated!\n");
    }
    else
        printf("Invalid option!\n");
}
void rackReport() {
    int rack[3][3];

    printf("Enter 3x3 Rack Matrix:\n");
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            scanf("%d", &rack[i][j]);

    int max = rack[0][0], min = rack[0][0];
    int maxR = 0, maxC = 0, minR = 0, minC = 0, total = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int val = rack[i][j];
            total += val;

            if (val > max) { max = val; maxR = i; maxC = j; }
            if (val < min) { min = val; minR = i; minC = j; }
        }
    }

    printf("Max Stock: %d at (%d,%d)\n", max, maxR, maxC);
    printf("Min Stock: %d at (%d,%d)\n", min, minR, minC);
    printf("Total Items: %d\n", total);
}
void stockValueReport() {
    if (count == 0) {
        printf("No products available!\n");
        return;
    }

    int highest = 0, lowest = 0;
    int totalValue = 0;

    printf("\nID\tQuantity\tPrice\tStockValue\n");

    for (int i = 0; i < count; i++) {
        int value = quantity[i] * price[i];
        totalValue += value;

        printf("%d\t%d\t\t%d\t%d\n", productID[i], quantity[i], price[i], value);

        if (value > quantity[highest] * price[highest])
            highest = i;

        if (value < quantity[lowest] * price[lowest])
            lowest = i;
    }

    printf("Highest Stock Value: Product ID %d\n", productID[highest]);
    printf("Lowest Stock Value: Product ID %d\n", productID[lowest]);
    printf("Total Warehouse Value: %d\n", totalValue);
}
void displayProducts() {
    if (count == 0) {
        printf("No products to display!\n");
        return;
    }

    printf("\nID\tQuantity\tPrice\n");
    for (int i = 0; i < count; i++)
        printf("%d\t%d\t\t%d\n", productID[i], quantity[i], price[i]);
}
