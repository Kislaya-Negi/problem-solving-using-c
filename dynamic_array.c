#include <stdio.h>
#include <stdlib.h>

int main(void) {
    size_t n = 3;
    int *numbers = malloc(n * sizeof *numbers);
    if (!numbers) { perror("malloc"); return 1; }
    for (size_t i = 0; i < n; ++i) numbers[i] = (int)(i + 1) * 10;

    size_t new_n = 5;
    int *temp = realloc(numbers, new_n * sizeof *numbers);
    if (!temp) { perror("realloc"); free(numbers); return 1; }
    numbers = temp;
    for (size_t i = n; i < new_n; ++i) numbers[i] = (int)(i + 1) * 10;

    for (size_t i = 0; i < new_n; ++i) printf("%d ", numbers[i]);
    puts("");
    free(numbers);
    numbers = NULL;
    return 0;
}
