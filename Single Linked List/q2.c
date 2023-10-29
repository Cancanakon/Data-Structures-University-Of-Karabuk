#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define a singly linked list structure
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at the beginning of the list
struct Node* insertNode(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    return newNode;
}

// Function to print the list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d", head->data);
        if (head->next != NULL) {
            printf("->");
        }
        head = head->next;
    }
    printf("\n");
}

// Function to compare two integers for sorting
int compare(const void *a, const void *b) {
    return ((int)b - (int)a);
}

int main() {
    struct Node* head = NULL;
    int numbers[100];

    // Seed the random number generator
    srand(time(NULL));

    // Generate 100 random numbers and add them to the list
    for (int i = 0; i < 100; i++) {
        numbers[i] = rand() % 100; // Generating random numbers between 0 and 99
        head = insertNode(head, numbers[i]);
    }

    // Sort the numbers array in descending order
    qsort(numbers, 100, sizeof(int), compare);

    // Print the sorted list
    printf("Sorted list: ");
    printList(head);

    return 0;
}