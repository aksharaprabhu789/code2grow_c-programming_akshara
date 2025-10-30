#include <stdio.h>

int main() {
    int choice;
    double balance = 10000.0;
    double amount;

    do {
        printf("Menu:");
        printf("\n 1.Deposit Money");
        printf("\n 2.Withdraw Money");
        printf("\n 3.Check Balance");
        printf("\n 4.Exit");
        printf("\n Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter amount to deposit: ");
                scanf("%lf", &amount);
                if (amount > 25000) {
                    balance += amount + (amount * 0.01);
                    printf("Bonus of %.2lf added!", amount * 0.01);
                } else {
                    balance += amount;
                }
                balance -= 5;
                printf("Service charge 5 applied.");
                printf("Updated Balance: %.2lf", balance);
                break;

            case 2:
                printf("Enter amount to withdraw: ");
                scanf("%lf", &amount);
                if (amount > balance) {
                    printf("Withdrawal not allowed, insufficient balance!");
                } else {
                    balance -= amount;
                    balance -= 5;
                    printf("Service charge 5 applied.");
                    printf("Updated Balance: %.2lf", balance);
                }
                break;

            case 3:
                printf("Current Balance: %.2lf", balance);
                break;

            case 4:
                printf("Thank you for banking with us!");
                break;

            default:
                printf("Invalid choice! Please select between 1-4.");
        }
    } while (choice != 4);

    return 0;
}
