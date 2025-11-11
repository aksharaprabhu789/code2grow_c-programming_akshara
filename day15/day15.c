#include <stdio.h>

int main() {
    int totalCustomers, roomType, days;
    char name[50];
    char bf, wifi, gym;
    float baseRate = 0, addServices = 0, subtotal, discount = 0, gst, finalBill;
    float totalRevenue = 0, highestBill = 0, lowestBill = 999999;
    int totalRooms = 0, i = 1;

    printf("Smart Hotel Room Booking System \n");
    printf("Enter total number of customers: ");
    scanf("%d", &totalCustomers);

    while(i <= totalCustomers) {
        printf("\n--- Customer %d ---\n", i);
        printf("Enter name: ");
        scanf("%s", name);

        printf("Enter room type (1-Deluxe, 2-Super Deluxe, 3-Suite): ");
        scanf("%d", &roomType);

        printf("Enter number of days: ");
        scanf("%d", &days);

        // Room selection
        if(roomType == 1)
            baseRate = 2500;
        else if(roomType == 2)
            baseRate = 4000;
        else if(roomType == 3)
            baseRate = 6000;
        else {
            printf("Invalid room type! Defaulting to Deluxe.\n");
            baseRate = 2500;
        }

        // Additional services
        printf("Breakfast (Y/N): ");
        scanf(" %c", &bf);
        printf("Wi-Fi (Y/N): ");
        scanf(" %c", &wifi);
        printf("Gym Access (Y/N): ");
        scanf(" %c", &gym);

        addServices = 0;
        if(bf == 'Y' || bf == 'y') addServices += 300 * days;
        if(wifi == 'Y' || wifi == 'y') addServices += 100 * days;
        if(gym == 'Y' || gym == 'y') addServices += 200 * days;

        // Bill calculations
        subtotal = (baseRate * days) + addServices;

        if(subtotal > 10000)
            discount = subtotal * 0.10;
        else
            discount = 0;

        gst = (subtotal - discount) * 0.12;
        finalBill = (subtotal - discount) + gst;

        // Display individual bill
        printf("\nBase Fare: ₹%.0f\n", baseRate * days);
        printf("Additional Services: ₹%.0f\n", addServices);
        printf("Subtotal: ₹%.0f\n", subtotal);
        printf("Discount (10%%): ₹%.0f\n", discount);
        printf("GST (12%%): ₹%.0f\n", gst);
        printf("Final Bill: ₹%.0f\n", finalBill);

        // Update summary
        totalRevenue += finalBill;
        totalRooms++;

        if(finalBill > highestBill)
            highestBill = finalBill;
        if(finalBill < lowestBill)
            lowestBill = finalBill;

        i++;
    }

    // Hotel summary
    printf("\nHotel Summary\n");
    printf("Total Rooms Booked: %d\n", totalRooms);
    printf("Total Revenue: ₹%.0f\n", totalRevenue);
    printf("Highest Bill: ₹%.0f\n", highestBill);
    printf("Lowest Bill: ₹%.0f\n", lowestBill);

    return 0;
}
