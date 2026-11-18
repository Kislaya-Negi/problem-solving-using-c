#include <stdio.h>
#include "common.h"

int main(void) {
    int a = 12, b = 5;
    printf("Sum = %d\n", add_numbers(a, b));
    printf("Product = %d\n", multiply_numbers(a, b));
    return 0;
}
