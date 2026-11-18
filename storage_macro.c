#include <stdio.h>

#define SQUARE(x) ((x) * (x))

void show_storage(void) {
    int automatic_value = 0;
    static int static_value = 0;
    ++automatic_value;
    ++static_value;
    printf("automatic=%d, static=%d\n", automatic_value, static_value);
}

int main(void) {
    show_storage();
    show_storage();
    show_storage();
    printf("SQUARE(3 + 2) = %d\n", SQUARE(3 + 2));
    return 0;
}
