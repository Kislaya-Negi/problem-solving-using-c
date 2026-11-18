#include <stdio.h>

int linear_search(const int a[], int n, int key, int *comparisons) {
    *comparisons = 0;
    for (int i = 0; i < n; ++i) {
        ++(*comparisons);
        if (a[i] == key) return i;
    }
    return -1;
}

void bubble_sort(int a[], int n, int *comparisons) {
    *comparisons = 0;
    for (int i = 0; i < n - 1; ++i) {
        int swapped = 0;
        for (int j = 0; j < n - 1 - i; ++j) {
            ++(*comparisons);
            if (a[j] > a[j + 1]) {
                int temp = a[j]; a[j] = a[j + 1]; a[j + 1] = temp;
                swapped = 1;
            }
        }
        if (!swapped) break;
    }
}

int main(void) {
    int data[] = {7, 3, 9, 1, 5}, n = 5, count;
    int index = linear_search(data, n, 9, &count);
    printf("Linear search: key 9 at index %d; comparisons = %d\n", index, count);
    bubble_sort(data, n, &count);
    printf("Sorted: ");
    for (int i = 0; i < n; ++i) printf("%d ", data[i]);
    printf("\nBubble-sort comparisons = %d\n", count);
    return 0;
}
