#include <stdio.h>
#include <stdlib.h>

int main() {
    int numbers[100]; // Assuming a maximum of 100 numbers
    int oddIndex = 0;
    int evenIndex = 99;
    int num;

    printf("Enter numbers, -1 to stop:\n");

    while (1) {
        scanf("%d", &num);

        if (num == -1) {
            break;
        }

        if (num % 2 == 1) {
            // Odd number, add to the beginning
            for (int i = oddIndex; i > 0; i--) {
                numbers[i] = numbers[i - 1];
            }
            numbers[0] = num;
            oddIndex++;
        } else {
            // Even number, add to the end
            for (int i = evenIndex; i < 99; i++) {
                numbers[i] = numbers[i + 1];
            }
            numbers[evenIndex] = num;
            evenIndex--;
        }
    }

    printf("Resulting list:\n");
    for (int i = 0; i <= oddIndex + (99 - evenIndex); i++) {
        printf("%d ", numbers[i]);
    }

    return 0;
}