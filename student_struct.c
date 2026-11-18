#include <stdio.h>
#include <string.h>
#define MAX 100

typedef struct {
    int roll;
    char name[50];
    float marks;
} Student;

int main(void) {
    Student students[MAX];
    int count = 0, choice, roll;
    do {
        printf("\n1.Add 2.Display 3.Search by roll 0.Exit\nChoice: ");
        if (scanf("%d", &choice) != 1) return 1;
        if (choice == 1) {
            if (count == MAX) { puts("Record limit reached."); continue; }
            printf("Roll, name (one word), marks: ");
            if (scanf("%d %49s %f", &students[count].roll,
                      students[count].name, &students[count].marks) != 3) return 1;
            ++count;
        } else if (choice == 2) {
            for (int i = 0; i < count; ++i)
                printf("%d %s %.2f\n", students[i].roll,
                       students[i].name, students[i].marks);
            if (!count) puts("No records.");
        } else if (choice == 3) {
            printf("Roll to find: "); if (scanf("%d", &roll) != 1) return 1;
            int found = 0;
            for (int i = 0; i < count; ++i)
                if (students[i].roll == roll) {
                    printf("Found: %d %s %.2f\n", students[i].roll,
                           students[i].name, students[i].marks);
                    found = 1; break;
                }
            if (!found) puts("Record not found.");
        } else if (choice != 0) puts("Invalid choice.");
    } while (choice != 0);
    return 0;
}
