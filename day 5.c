#include <stdio.h>

int main() {
    int age, health;
    char gender;
    float premium = 0.0;

    // Input Section
    printf("Enter age: ");
    scanf("%d", &age);

    printf("Enter gender (M/F): ");
    scanf(" %c", &gender); // space before %c to skip newline

    printf("Health condition (1-Healthy / 0-Unhealthy): ");
    scanf("%d", &health);

    // Display Customer Details
    printf("\nCustomer Details:\n");
    printf("Age: %d\n", age);
    printf("Gender: %c\n", gender);
    printf("Health: %s\n", (health == 1) ? "Healthy" : "Unhealthy");

    // Determine Premium Based on Conditions
    if (age < 25) {
        if (health == 1)
            premium = 5000;
        else
            printf("Status: Not Eligible for Insurance\n");
    }
    else if (age >= 25 && age <= 40) {
        if (health == 1)
            premium = 7000;
        else
            premium = 9500;
    }
    else if (age >= 41 && age <= 60) {
        if (health == 1)
            premium = 10000;
        else
            premium = 13000;
    }
    else if (age > 60) {
        if (health == 0) {
            printf("Status: Not Eligible for Insurance\n");
            return 0; // Exit if not eligible
        } else {
            premium = 15000;
        }
    }

    // Apply 10% discount for females
    if (gender == 'F' || gender == 'f') {
        premium = premium - (premium * 0.10);
    }

    // Display Final Premium
    if (premium > 0)
        printf("Final Premium: ₹%.2f\n", premium);

    return 0;
}
