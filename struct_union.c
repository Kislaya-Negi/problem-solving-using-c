#include <stdio.h>
#include <stddef.h>

typedef struct {
    char code;
    int number;
    double value;
} RecordStruct;

typedef union {
    char code;
    int number;
    double value;
} RecordUnion;

int main(void) {
    printf("sizeof(struct) = %zu\n", sizeof(RecordStruct));
    printf("sizeof(union)  = %zu\n", sizeof(RecordUnion));
    printf("Struct offsets: code=%zu number=%zu value=%zu\n",
           offsetof(RecordStruct, code), offsetof(RecordStruct, number),
           offsetof(RecordStruct, value));
    printf("Union members all begin at offset 0 (same storage).\n");
    return 0;
}
