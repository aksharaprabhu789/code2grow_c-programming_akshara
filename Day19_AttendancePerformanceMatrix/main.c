#include <stdio.h>
int main() {
    int attendance[5][5];
    int marks[5][5];
    char names[5][20];

    int i, j;
    int choice;
    printf("Enter names of 5 students:\n");
    for(i = 0; i < 5; i++){
        printf("Student %d: ", i+1);
        scanf("%s", names[i]);
    }

    printf("\nEnter Attendance Matrix (1 = Present, 0 = Absent):\n");
    for(i = 0; i < 5; i++){
        printf("Attendance of %s (5 classes):\n", names[i]);
        for(j = 0; j < 5; j++){
            scanf("%d", &attendance[i][j]);
        }
    }

    printf("\nEnter Marks Matrix (Marks of 5 subjects):\n");
    for(i = 0; i < 5; i++){
        printf("Marks of %s:\n", names[i]);
        for(j = 0; j < 5; j++){
            scanf("%d", &marks[i][j]);
        }
    }

    while(1){
        printf("\n========== MENU ==========\n");
        printf("1. Display Attendance Matrix\n");
        printf("2. Display Marks Matrix\n");
        printf("3. Attendance Report\n");
        printf("4. Performance Report\n");
        printf("5. Grade Report\n");
        printf("6. Exit\n");
        printf("==========================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if(choice == 6) break;

        switch(choice){

            case 1:
                printf("\nAttendance Matrix:\n");
                for(i = 0; i < 5; i++){
                    printf("%s: ", names[i]);
                    for(j = 0; j < 5; j++){
                        printf("%d ", attendance[i][j]);
                    }
                    printf("\n");
                }
                break;

            case 2:
                printf("\nMarks Matrix:\n");
                for(i = 0; i < 5; i++){
                    printf("%s: ", names[i]);
                    for(j = 0; j < 5; j++){
                        printf("%d ", marks[i][j]);
                    }
                    printf("\n");
                }
                break;

            case 3: {
                int totalPresent[5] = {0};
                int totalAbsent[5] = {0};
                int highest = -1, lowest = 99;
                int highIndex = 0, lowIndex = 0;

                for(i = 0; i < 5; i++){
                    for(j = 0; j < 5; j++){
                        if(attendance[i][j] == 1)
                            totalPresent[i]++;
                        else
                            totalAbsent[i]++;
                    }

                    if(totalPresent[i] > highest){
                        highest = totalPresent[i];
                        highIndex = i;
                    }
                    if(totalPresent[i] < lowest){
                        lowest = totalPresent[i];
                        lowIndex = i;
                    }
                }

                printf("\nAttendance Report:\n");
                for(i = 0; i < 5; i++){
                    printf("%s -> Present: %d | Absent: %d\n",
                            names[i], totalPresent[i], totalAbsent[i]);
                }

                printf("\nHighest Attendance: %s (%d)\n", names[highIndex], highest);
                printf("Lowest Attendance: %s (%d)\n", names[lowIndex], lowest);
                break;
            }

            case 4: {
                int totalMarks[5] = {0};
                float avg[5];
                int high = -1, low = 999;
                int topper = 0, weak = 0;

                for(i = 0; i < 5; i++){
                    for(j = 0; j < 5; j++){
                        totalMarks[i] += marks[i][j];
                    }
                    avg[i] = totalMarks[i] / 5.0;

                    if(totalMarks[i] > high){
                        high = totalMarks[i];
                        topper = i;
                    }
                    if(totalMarks[i] < low){
                        low = totalMarks[i];
                        weak = i;
                    }
                }

                printf("\nPerformance Report:\n");
                for(i = 0; i < 5; i++){
                    printf("%s -> Total: %d | Average: %.2f\n",
                            names[i], totalMarks[i], avg[i]);
                }

                printf("\nClass Topper: %s (%d)\n", names[topper], high);
                printf("Lowest Performer: %s (%d)\n", names[weak], low);
                break;
            }
            case 5: {
                float avg;
                printf("\nGrade Report:\n");

                for(i = 0; i < 5; i++){
                    int sum = 0;
                    for(j = 0; j < 5; j++){
                        sum += marks[i][j];
                    }
                    avg = sum / 5.0;

                    char grade;

                    if(avg >= 90) grade = 'A'+0;  // A+
                    else if(avg >= 80) grade = 'A';
                    else if(avg >= 70) grade = 'B';
                    else if(avg >= 60) grade = 'C';
                    else if(avg >= 50) grade = 'D';
                    else grade = 'F';

                    printf("%s -> Average: %.2f | Grade: %c\n", names[i], avg, grade);
                }
                break;
            }

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

