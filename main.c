#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define SUBJECTS 3

struct Student {
    int id;
    char name[50];
    float marks[SUBJECTS];
    float total;
    float percentage;
};

struct Student students[MAX];
int count = 0;

void addStudent() {
    if (count >= MAX) {
        printf("\nStudent database is full!\n");
        return;
    }

    printf("\nEnter Student ID: ");
    scanf("%d", &students[count].id);

    printf("Enter Student Name: ");
    scanf(" %[^\n]", students[count].name);

    students[count].total = 0;

    printf("Enter marks for %d subjects:\n", SUBJECTS);
    for (int i = 0; i < SUBJECTS; i++) {
        do {
            printf("Subject %d: ", i + 1);
            scanf("%f", &students[count].marks[i]);

            if (students[count].marks[i] < 0 || students[count].marks[i] > 100) {
                printf("Marks must be between 0 and 100.\n");
            }
        } while (students[count].marks[i] < 0 || students[count].marks[i] > 100);

        students[count].total += students[count].marks[i];
    }

    students[count].percentage = students[count].total / SUBJECTS;
    count++;

    printf("\nStudent added successfully!\n");
}

void displayResults() {
    if (count == 0) {
        printf("\nNo student records found.\n");
        return;
    }

    printf("\n========== STUDENT RESULTS ==========\n");

    for (int i = 0; i < count; i++) {
        printf("\nStudent #%d", i + 1);
        printf("\nID          : %d", students[i].id);
        printf("\nName        : %s", students[i].name);
        printf("\nTotal Marks : %.2f", students[i].total);
        printf("\nPercentage  : %.2f%%", students[i].percentage);

        if (students[i].percentage >= 40)
            printf("\nResult      : PASS\n");
        else
            printf("\nResult      : FAIL\n");

        printf("-------------------------------------\n");
    }
}

void searchStudent() {
    int id, found = 0;

    if (count == 0) {
        printf("\nNo student records available.\n");
        return;
    }

    printf("\nEnter Student ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            printf("\nStudent Found!");
            printf("\nID          : %d", students[i].id);
            printf("\nName        : %s", students[i].name);
            printf("\nTotal Marks : %.2f", students[i].total);
            printf("\nPercentage  : %.2f%%", students[i].percentage);

            if (students[i].percentage >= 40)
                printf("\nResult      : PASS\n");
            else
                printf("\nResult      : FAIL\n");

            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nStudent not found!\n");
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n=====================================");
        printf("\n   STUDENT RESULT MANAGEMENT SYSTEM");
        printf("\n=====================================");
        printf("\n1. Add Student");
        printf("\n2. Display All Results");
        printf("\n3. Search Student");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;

            case 2:
                displayResults();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                printf("\nThank you for using the system!\n");
                exit(0);

            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }

    return 0;
}
