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

// Function to delete the node following the node with a given name
struct Student* deleteNextNodeByName(struct Student* head, const char* name) {
    struct Student* current = head;

    while (current != NULL && current->next != NULL) {
        if (strcmp(current->name, name) == 0) {
            struct Student* temp = current->next;
            current->next = current->next->next;
            free(temp); // Delete the next node
            return head;
        }
        current = current->next;
    }

    return head; // No deletion made
}

// Function to print all student information
void printStudents(struct Student* head) {
    struct Student* current = head;
    while (current != NULL) {
        printf("%d- %s %d %d\n", current->number, current->name, current->age, current->number);
        current = current->next;
    }
}

int main() {
    struct Student* head = NULL;

    // Insert some students into the list
    head = insertStudent(head, 201, "Saliha", 27);
    head = insertStudent(head, 203, "Ece", 19);
    head = insertStudent(head, 205, "John", 22);
    head = insertStudent(head, 207, "Alice", 20);

    // Delete the node following the student with the name "Ece"
    const char* searchName = "Ece";
    head = deleteNextNodeByName(head, searchName);

    // Print the updated student list
    printf("Student Information:\n");
    printStudents(head);

    return 0;
}