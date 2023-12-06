#include <stdio.h>

int main() {
    int choice;
    float num1, num2, result;

    // User chooses the operation
    printf("Choose an operation:\n");
    printf("1. Addition (+)\n2. Subtraction (-)\n3. Multiplication (*)\n4. Division (/)\n");
    printf("Your choice = ");
    scanf("%d", &choice);

    // Check if the operation choice is valid
    if (choice >= 1 && choice <= 4) {
        // User inputs first number
        printf("Enter the first number (num1): ");
        // Check if num1 is a valid float
        if (scanf("%f", &num1) != 1) {
            printf("Error: Invalid input for num1. Please enter a valid number.\n");
            return 1;
        }

        // User inputs second number
        printf("Enter the second number (num2): ");
        // Check if num2 is a valid float
        if (scanf("%f", &num2) != 1) {
            printf("Error: Invalid input for num2. Please enter a valid number.\n");
            return 1;
        }
    } else {
        // Display error message and exit
        printf("Error: Invalid operation choice. Please select a valid operation.\n");
        return 1;
    }

    // Perform the selected operation
    switch (choice) {
        case 1:
            result = num1 + num2;
            break;
        case 2:
            result = num1 - num2;
            break;
        case 3:
            result = num1 * num2;
            break;
        case 4:
            if (num2 != 0) {
                result = num1 / num2;
            } else {
                printf("Error: Division by zero is not allowed.\n");
                return 1; // Exit the program with an error code
            }
            break;
    }

    // Display the result
    printf("Result: %.2f\n", result);

    return 0;
}
