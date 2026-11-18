#include <stdio.h>

int main(void) {
    int values[] = {10, 20, 30, 40};
    int *ptr = values;
    int **ptr_to_ptr = &ptr;
    int sum = 0;
    for (int i = 0; i < 4; ++i) {
        sum += *(*ptr_to_ptr + i);
        printf("%d ", *(*ptr_to_ptr + i));
    }
    printf("\nSum = %d\nAverage = %.2f\n", sum, sum / 4.0);
    return 0;
}
