#include <stdio.h>

int main() {
    char name[50], regno[20], section[10];
    int n, i, choice;
    float salary[10], total = 0, avg, temp;

    printf(" Employee Salary Analysis System \n");
    printf("Enter Student Name: ");
    gets(name);
    printf("Enter Registration Number: ");
    gets(regno);
    printf("Enter Section: ");
    gets(section);

    printf("\nEnter number of employees (<=10): ");
    scanf("%d", &n);
    printf("Enter salaries:\n");
    for (i = 0; i < n; i++) {
        printf("%d: ", i + 1);
        scanf("%f", &salary[i]);
    }

    do {
        printf("\n Menu \n");
        printf("1. Display All Salaries\n");
        printf("2. Display Total and Average Salary\n");
        printf("3. Display Highest and Lowest Salary\n");
        printf("4. Count Above/Below Average\n");
        printf("5. Display Sorted Salaries (Ascending)\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nAll Salaries:\n");
                for (i = 0; i < n; i++)
                    printf("%.2f ", salary[i]);
                printf("\n");
                break;

            case 2:
                total = 0;
                for (i = 0; i < n; i++)
                    total += salary[i];
                avg = total / n;
                printf("\nTotal Salary = %.2f\nAverage Salary = %.2f\n", total, avg);
                break;

            case 3: {
                float highest = salary[0], lowest = salary[0];
                for (i = 1; i < n; i++) {
                    if (salary[i] > highest) highest = salary[i];
                    if (salary[i] < lowest) lowest = salary[i];
                }
                printf("\nHighest Salary = %.2f\nLowest Salary = %.2f\n", highest, lowest);
                break;
            }

            case 4:
                total = 0;
                for (i = 0; i < n; i++)
                    total += salary[i];
                avg = total / n;
                int above = 0, below = 0;
                for (i = 0; i < n; i++) {
                    if (salary[i] > avg) above++;
                    else if (salary[i] < avg) below++;
                }
                printf("\nAbove Average = %d\nBelow Average = %d\n", above, below);
                break;

            case 5:
                for (i = 0; i < n - 1; i++) {
                    for (int j = 0; j < n - i - 1; j++) {
                        if (salary[j] > salary[j + 1]) {
                            temp = salary[j];
                            salary[j] = salary[j + 1];
                            salary[j + 1] = temp;
                        }
                    }
                }
                printf("\nSalaries in Ascending Order:\n");
                for (i = 0; i < n; i++)
                    printf("%.2f ", salary[i]);
                printf("\n");
                break;

            case 6:
                printf("\nExiting Program...\n");
                break;

            default:
                printf("\nInvalid Choice! Try again.\n");
        }

        printf("\nSubmitted by: %s | Reg No: %s | Section: %s\n", name, regno, section);
        printf("Challenge Day 17 - Code2Grow Program\n");

    } while (choice != 6);

    return 0;
}
