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

// Function to find and print the student with the longest name
void printStudentWithLongestName(struct Student* head) {
    struct Student* current = head;
    int maxNameLength = 0;
    const char* longestName = NULL;

    while (current != NULL) {
        int currentNameLength = strlen(current->name);
        if (currentNameLength > maxNameLength) {
            maxNameLength = currentNameLength;
            longestName = current->name;
        }
        current = current->next;
    }

    if (longestName != NULL) {
        printf("The longest name in the list: %s Length: %d\n", longestName, maxNameLength);
    } else {
        printf("No student records in the list.\n");
    }
}

int main() {
    struct Student* head = NULL;

    // Insert some students into the list
    head = insertStudent(head, 201, "Saliha", 27);
    head = insertStudent(head, 203, "Ece", 19);
    head = insertStudent(head, 205, "John", 22);
    head = insertStudent(head, 207, "Abdurrahmangazi", 20);

    // Find and print the student with the longest name
    printf("Student Information:\n");
    printStudentWithLongestName(head);

    return 0;
}