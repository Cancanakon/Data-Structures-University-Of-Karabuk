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

// Function to print all student information and count students
void printStudents(struct Student* head) {
    int count = 1;

    while (head != NULL) {
        printf("%d- %s %d %d\n", count, head->name, head->age, head->number);
        count++;
        head = head->next;
    }
}

int main() {
    struct Student* head = NULL;

    // Insert some students into the list
    head = insertStudent(head, 201, "Saliha", 27);
    head = insertStudent(head, 203, "Ece", 19);

    // Print student information and count
    printf("Student Information:\n");
    printStudents(head);

    return 0;
}