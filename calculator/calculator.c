#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);

int main(int argc, char *argv[]) {
    FILE *calculation_history;
    calculation_history = fopen("calculation_history.txt", "a");

    // Check the number of arguments
    if (argc != 4) {
        printf("Error: Incorrect number of arguments.\n");
        printf("Usage: %s <number1> <operator> <number2>\n", argv[0]);
        return 1;
    }

    // Parse the first number
    char *endptr;
    double num1 = strtod(argv[1], &endptr);
    if (*endptr != '\0') {
        printf("Error: '%s' is not a valid number.\n", argv[1]);
        return 1;
    }

    // Parse the operator
    char operator = argv[2][0];
    if (argv[2][1] != '\0' || !(operator == '+' || operator == '-' || operator == '*' || operator == '/')) {
        printf("Error: '%s' is not a valid operator.\n", argv[2]);
        return 1;
    }

    // Parse the second number
    double num2 = strtod(argv[3], &endptr);
    if (*endptr != '\0') {
        printf("Error: '%s' is not a valid number.\n", argv[3]);
        return 1;
    }

    // Handle division by zero
    if (operator == '/' && num2 == 0) {
        printf("Error: Division by zero is not allowed.\n");
        return 1;
    }

    // Perform the calculation
    double result;
    switch (operator) {
        case '+':
            result = add(num1, num2);
            break;
        case '-':
            result = subtract(num1, num2);
            break;
        case '*':
            result = multiply(num1, num2);
            break;
        case '/':
            result = divide(num1, num2);
            break;
        default:
            printf("Error: Unknown error occurred.\n");
            return 1;
    }

    // Display the result
    printf("%.2f %s %.2f = %.2f\n",num1,argv[2],num2, result);
    // write to file
    fprintf(calculation_history, "%.2f %s %.2f = %.2f\n",num1,argv[2],num2, result);
    fcloseall();    
    return 0;
}

// Function for addition
double add(double a, double b) {
    return a + b;
}

// Function for subtraction
double subtract(double a, double b) {
    return a - b;
}

// Function for multiplication
double multiply(double a, double b) {
    return a * b;
}

// Function for division
double divide(double a, double b) {
    if (b == 0) {
        printf("Error: Division by zero is not allowed.\n");
        return 0; // Return 0 as a default; you can modify based on your design.
    }
    return a / b;
}
