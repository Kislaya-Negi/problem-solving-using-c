#include <stdio.h>

typedef struct { int roll; char name[40]; float marks; } Student;

int main(void) {
    Student input[] = {{1, "Asha", 88.5f}, {2, "Ravi", 91.0f}};
    FILE *fp = fopen("students.dat", "w");
    if (!fp) { perror("students.dat"); return 1; }
    for (int i = 0; i < 2; ++i)
        if (fprintf(fp, "%d %s %.2f\n", input[i].roll,
                    input[i].name, input[i].marks) < 0) {
            perror("write"); fclose(fp); return 1;
        }
    if (fclose(fp) != 0) { perror("close"); return 1; }

    fp = fopen("students.dat", "r");
    if (!fp) { perror("students.dat"); return 1; }
    Student s;
    puts("Records read from file:");
    while (fscanf(fp, "%d %39s %f", &s.roll, s.name, &s.marks) == 3)
        printf("%d %s %.2f\n", s.roll, s.name, s.marks);
    if (ferror(fp)) { perror("read"); fclose(fp); return 1; }
    fclose(fp);
    return 0;
}
