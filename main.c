#include <stdio.h>

#define MAX 100

struct Student {
    int id;
    char name[50];
    float marks[3];
    float total;
    float percentage;
};

struct Student students[MAX];
int count = 0;

// Add student
void addStudent() {
    printf("Enter ID: ");
    scanf("%d", &students[count].id);

    printf("Enter Name: ");
    scanf(" %[^\n]", students[count].name);

    printf("Enter marks for 3 subjects:\n");
    students[count].total = 0;

    for(int i = 0; i < 3; i++) {
        printf("Subject %d: ", i+1);
        scanf("%f", &students[count].marks[i]);
        students[count].total += students[count].marks[i];
    }

    students[count].percentage = students[count].total / 3;

    count++;
    printf("Student added successfully!\n");
}

// Display result
void displayResults() {
    for(int i = 0; i < count; i++) {
        printf("\nID: %d", students[i].id);
        printf("\nName: %s", students[i].name);
        printf("\nTotal: %.2f", students[i].total);
        printf("\nPercentage: %.2f", students[i].percentage);

        if(students[i].percentage >= 40)
            printf("\nResult: Pass\n");
        else
            printf("\nResult: Fail\n");
    }
}

// Search student
void searchStudent() {
    int id, found = 0;
    printf("Enter ID to search: ");
    scanf("%d", &id);

    for(int i = 0; i < count; i++) {
        if(students[i].id == id) {
            printf("\nName: %s", students[i].name);
            printf("\nPercentage: %.2f\n", students[i].percentage);
            found = 1;
            break;
        }
    }

    if(!found)
        printf("Student not found!\n");
}

int main() {
    int choice;

    while(1) {
        printf("\n--- Student Result System ---\n");
        printf("1. Add Student\n");
        printf("2. Display Results\n");
        printf("3. Search Student\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addStudent(); break;
            case 2: displayResults(); break;
            case 3: searchStudent(); break;
            case 4: return 0;
            default: printf("Invalid choice\n");
        }
    }
}
