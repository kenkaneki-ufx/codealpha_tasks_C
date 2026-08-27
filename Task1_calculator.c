// Task 1: Basic Calculator Program
// CodeAlpha C Programming Internship
// Author: Aryan Pandey

#include <stdio.h>

int main() {
    float num1, num2, result;
    int choice;
    char cont;

    printf("\n--- Simple Calculator ---\n\n");

    do {
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 5)
            break;

        if (choice < 1 || choice > 5) {
            printf("Wrong choice! Try again.\n\n");
            continue;
        }

        printf("Enter first number: ");
        scanf("%f", &num1);
        printf("Enter second number: ");
        scanf("%f", &num2);

        switch (choice)
        {
            case 1:
                result = num1 + num2;
                printf("Result = %.2f\n\n", result);
                break;
            case 2:
                result = num1 - num2;
                printf("Result = %.2f\n\n", result);
                break;
            case 3:
                result = num1 * num2;
                printf("Result = %.2f\n\n", result);
                break;
            case 4:
                if (num2 == 0) 
                    printf("Cannot divide by zero!\n\n");
                else
                {
                    result = num1 / num2;
                    printf("Result = %.2f\n\n", result);
                }
            default :
                printf("Invalid choice...");
        }
        printf("Do you want to continue? (y/n): ");
        scanf(" %c", &cont);

    } while (cont == 'y' || cont == 'Y');

    printf("Thanks for using calculator!\n");
    return 0;
}
