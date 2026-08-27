// Task 3: Student Management System
// CodeAlpha C Programming Internship
// Author: Aryan Pandey

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int roll;
    char name[50];
    float marks;
};

void addStudent() {
    struct Student s;
    FILE *fp;

    printf("\n--- Add Student ---\n");
    printf("Roll no: ");
    scanf("%d", &s.roll);
    printf("Name: ");
    scanf(" %[^\n]", s.name);
    printf("Marks: ");
    scanf("%f", &s.marks);

    fp = fopen("students.dat", "ab");
    fwrite(&s, sizeof(s), 1, fp);
    fclose(fp);
    printf("Added!\n");
}

void displayAll() {
    struct Student s;
    FILE *fp;

    fp = fopen("students.dat", "rb");
    if (fp == NULL) {
        printf("\nNo records yet!\n");
        return;
    }

    printf("\n--- All Students ---\n");
    printf("%-8s %-20s %-8s\n", "Roll", "Name", "Marks");
    printf("--------------------------------\n");

    while (fread(&s, sizeof(s), 1, fp) == 1)
        printf("%-8d %-20s %-8.2f\n", s.roll, s.name, s.marks);

    fclose(fp);
}

void searchStudent() {
    struct Student s;
    FILE *fp;
    int roll, found = 0;

    printf("\nRoll to search: ");
    scanf("%d", &roll);

    fp = fopen("students.dat", "rb");
    if (fp == NULL) {
        printf("No records!\n");
        return;
    }

    while (fread(&s, sizeof(s), 1, fp) == 1) {
        if (s.roll == roll) {
            printf("\nRoll: %d\nName: %s\nMarks: %.2f\n", s.roll, s.name, s.marks);
            found = 1;
            break;
        }
    }
    fclose(fp);

    if (!found)
        printf("Not found!\n");
}

void updateStudent() {
    struct Student s;
    FILE *fp, *temp;
    int roll, found = 0;

    printf("\nRoll to update: ");
    scanf("%d", &roll);

    fp = fopen("students.dat", "rb");
    temp = fopen("temp.dat", "wb");

    while (fread(&s, sizeof(s), 1, fp) == 1) {
        if (s.roll == roll) {
            printf("Current: %s, %.2f\n", s.name, s.marks);
            printf("New name: ");
            scanf(" %[^\n]", s.name);
            printf("New marks: ");
            scanf("%f", &s.marks);
            found = 1;
        }
        fwrite(&s, sizeof(s), 1, temp);
    }

    fclose(fp);
    fclose(temp);
    remove("students.dat");
    rename("temp.dat", "students.dat");

    if (found)
        printf("Updated!\n");
    else
        printf("Not found!\n");
}

void deleteStudent() {
    struct Student s;
    FILE *fp, *temp;
    int roll, found = 0;

    printf("\nRoll to delete: ");
    scanf("%d", &roll);

    fp = fopen("students.dat", "rb");
    temp = fopen("temp.dat", "wb");

    while (fread(&s, sizeof(s), 1, fp) == 1) {
        if (s.roll == roll) {
            found = 1;
            continue;
        }
        fwrite(&s, sizeof(s), 1, temp);
    }

    fclose(fp);
    fclose(temp);
    remove("students.dat");
    rename("temp.dat", "students.dat");

    if (found)
        printf("Deleted!\n");
    else
        printf("Not found!\n");
}

int main() {
    int ch;

    do {
        printf("\n===== Student Records =====\n");
        printf("1. Add\n");
        printf("2. Display All\n");
        printf("3. Search\n");
        printf("4. Update\n");
        printf("5. Delete\n");
        printf("6. Exit\n");
        printf("Choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: addStudent(); break;
            case 2: displayAll(); break;
            case 3: searchStudent(); break;
            case 4: updateStudent(); break;
            case 5: deleteStudent(); break;
            case 6: break;
            default: printf("Invalid!\n");
        }
    } while (ch != 6);

    return 0;
}
