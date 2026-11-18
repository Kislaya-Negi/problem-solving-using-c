#include <stdio.h>

double add(double a, double b) { return a + b; }
double subtract(double a, double b) { return a - b; }
double multiply(double a, double b) { return a * b; }
double divide(double a, double b) { return a / b; }

int main(void) {
    double (*operations[4])(double, double) = {add, subtract, multiply, divide};
    const char *names[] = {"Add", "Subtract", "Multiply", "Divide"};
    int choice; double a, b;
    printf("0 Add, 1 Subtract, 2 Multiply, 3 Divide: ");
    if (scanf("%d", &choice) != 1 || choice < 0 || choice > 3) {
        puts("Invalid choice."); return 1;
    }
    printf("Enter two numbers: ");
    if (scanf("%lf %lf", &a, &b) != 2) return 1;
    if (choice == 3 && b == 0) { puts("Cannot divide by zero."); return 1; }
    printf("%s result = %.2f\n", names[choice], operations[choice](a, b));
    return 0;
}
