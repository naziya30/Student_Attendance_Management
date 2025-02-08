#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STUDENTS 200

char stuName[MAX_STUDENTS][30]; // Array to store student names
int presentAttendance[MAX_STUDENTS] = {0}; // Array to track present count
int absentAttendance[MAX_STUDENTS] = {0}; // Array to track absent count
int indexNumber = 0; // Keeps track of the number of students

// Function to check attendance records
void checkAttendance() {
    printf("\nTotal Attendance Report:\n");
    printf("----------------------------\n");
    printf("ID\tStudent Name\tPresent\tAbsent\n");

    for (int i = 0; i < indexNumber; i++) {
        printf("%d\t%s\t\t%d\t%d\n", i + 1, stuName[i], presentAttendance[i], absentAttendance[i]);
    }
}

// Function to add students
void addStudent() {
    int num;
    printf("Enter the number of students you want to add: ");
    scanf("%d", &num);
    getchar(); // To clear newline character

    for (int i = 0; i < num; i++) {
        printf("\nEnter student name: ");
        fgets(stuName[indexNumber], sizeof(stuName[indexNumber]), stdin);
        stuName[indexNumber][strcspn(stuName[indexNumber], "\n")] = 0; // Remove trailing newline
        indexNumber++;
    }
}

// Function to take attendance
void takeAttendance() {
    char ch;
    printf("\nEnter Y for Present and N for Absent\n");

    for (int i = 0; i < indexNumber; i++) {
        printf("%d. Is %s present? (Y/N): ", i + 1, stuName[i]);
        scanf(" %c", &ch);

        if (ch == 'Y' || ch == 'y') {
            presentAttendance[i]++;
        } else if (ch == 'N' || ch == 'n') {
            absentAttendance[i]++;
        } else {
            printf("Invalid input, please enter Y or N.\n");
            i--; // Repeat this student's input
        }
    }
}

// Function to remove a student
void removeStudent() {
    char name[30];
    printf("Enter the student name to remove: ");
    getchar(); // Clear newline
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0; // Remove trailing newline

    int found = 0;
    for (int i = 0; i < indexNumber; i++) {
        if (strcmp(name, stuName[i]) == 0) {
            // Shift remaining students
            for (int j = i; j < indexNumber - 1; j++) {
                strcpy(stuName[j], stuName[j + 1]);
                presentAttendance[j] = presentAttendance[j + 1];
                absentAttendance[j] = absentAttendance[j + 1];
            }
            indexNumber--; // Decrease the student count
            printf("%s has been removed.\n", name);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student name not found!\n");
    }
}

// Main function
int main() {
    int choice;

    do {
        printf("\n--- Attendance Management System ---\n");
        printf("1. Add Student\n");
        printf("2. Take Attendance\n");
        printf("3. Check Attendance\n");
        printf("4. Remove Student\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                takeAttendance();
                break;
            case 3:
                checkAttendance();
                break;
            case 4:
                removeStudent();
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
