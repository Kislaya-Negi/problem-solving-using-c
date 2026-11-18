#include <stdio.h>

int main(void) {
    int choice;
    double a, b;
    do {
        printf("\n1.Add  2.Subtract  3.Multiply  4.Divide  0.Exit\n");
        printf("Choice: ");
        if (scanf("%d", &choice) != 1) {
            puts("Invalid input: enter an integer choice.");
            return 1;
        }
        if (choice == 0) break;
        if (choice < 1 || choice > 4) {
            puts("Invalid choice. Select 0 to 4.");
            continue;
        }
        printf("Enter two numbers: ");
        if (scanf("%lf %lf", &a, &b) != 2) {
            puts("Invalid numeric input.");
            return 1;
        }
        switch (choice) {
            case 1: printf("Result = %.2f\n", a + b); break;
            case 2: printf("Result = %.2f\n", a - b); break;
            case 3: printf("Result = %.2f\n", a * b); break;
            case 4:
                if (b == 0.0) puts("Error: division by zero.");
                else printf("Result = %.2f\n", a / b);
                break;
        }
    } while (1);
    puts("Calculator closed.");
    return 0;
}
