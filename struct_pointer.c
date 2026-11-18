#include <stdio.h>

typedef struct { int id; float marks; } Student;

void update_student(Student *student) {
    student->marks = 95.0f;
    student->id = 202;
}

Student update_copy(Student student) {
    student.marks = 50.0f;
    return student;
}

int main(void) {
    Student s = {101, 72.5f};
    update_student(&s);
    printf("After pointer function: id=%d marks=%.1f\n", s.id, s.marks);
    Student copy = update_copy(s);
    printf("Original after value function: marks=%.1f; returned copy marks=%.1f\n",
           s.marks, copy.marks);
    return 0;
}
