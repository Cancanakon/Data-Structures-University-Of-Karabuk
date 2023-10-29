#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct for student information
struct Student {
    int number;
    char name[50];
    int age;
    struct Student* next;
};

// Function to insert a new student at the beginning of the list
struct Student* insertStudent(struct Student* head, int number, const char* name, int age) {
    struct Student* newStudent = (struct Student*)malloc(sizeof(struct Student));
    newStudent->number = number;
    strcpy(newStudent->name, name);
    newStudent->age = age;
    newStudent->next = head;
    return newStudent;
}

// Function to search for a student by name
struct Student* searchStudentByName(struct Student* head, const char* name) {
    struct Student* current = head;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return current;
        }
        current = current->next;
    }

    return NULL; // Student with the given name not found
}

int main() {
    struct Student* head = NULL;

    // Insert some students into the list
    head = insertStudent(head, 201, "Saliha", 27);
    head = insertStudent(head, 203, "Ece", 19);

    // Search for a student by name
    const char* searchName = "Saliha";
    struct Student* foundStudent = searchStudentByName(head, searchName);

    if (foundStudent != NULL) {
        printf("Student found: %s %d %d\n", foundStudent->name, foundStudent->age, foundStudent->number);
    } else {
        printf("Student with name '%s' not found.\n", searchName);
    }

    return 0;
}