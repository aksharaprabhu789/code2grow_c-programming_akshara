#include <stdio.h>

int main() {

    int mark1, mark2, mark3, mark4, mark5;
    int attendance;
    float total_marks, total_percentage;
    char grade;
    char remarks[20];


    printf("Enter marks in 5 subjects (0-100): ");
    scanf("%d %d %d %d %d", &mark1, &mark2, &mark3, &mark4, &mark5);

    printf("Enter attendance percentage (0-100): ");
    scanf("%d", &attendance);


    total_marks = mark1 + mark2 + mark3 + mark4 + mark5;
    total_percentage = (total_marks / 500.0) * 100.0;


    if (attendance < 75) {
        grade = 'F';
        sprintf(remarks, "Fail");
    } else {

        if (total_percentage >= 45 && total_percentage <= 49 && attendance >= 90) {
            total_percentage += 5;
        }

        if (total_percentage >= 90) {
            grade = 'A';
            sprintf(remarks, "Excellent");
        } else if (total_percentage >= 80) {
            grade = 'A';
            sprintf(remarks, "Very Good");
        } else if (total_percentage >= 70) {
            grade = 'B';
            sprintf(remarks, "Good");
        } else if (total_percentage >= 60) {
            grade = 'C';
            sprintf(remarks, "Average");
        } else if (total_percentage >= 50) {
            grade = 'D';
            sprintf(remarks, "Pass");
        } else {
            grade = 'F';
            sprintf(remarks, "Fail");
        }
    }


    printf("\nTotal Percentage: %.2f%%\n", total_percentage);
    printf("Attendance: %d%%\n", attendance);
    printf("Final Grade: %c\n", grade);
    printf("Remarks: %s\n", remarks);

    return 0;
}
