#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    char s[200], reversed[200];
    int vowels = 0, palindrome = 1;
    printf("Enter a single word: ");
    if (scanf("%199s", s) != 1) return 1;

    char *p = s;                         /* Pointer traversal */
    while (*p) {
        char c = (char)tolower((unsigned char)*p);
        if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u') ++vowels;
        ++p;
    }

    size_t len = strlen(s);
    for (size_t i = 0; i < len; ++i)
        reversed[i] = s[len - 1 - i];
    reversed[len] = '\0';

    for (size_t i = 0; i < len / 2; ++i) {
        if (tolower((unsigned char)s[i]) !=
            tolower((unsigned char)s[len - 1 - i])) {
            palindrome = 0;
            break;
        }
    }
    printf("Vowels = %d\nReverse = %s\nPalindrome = %s\n",
           vowels, reversed, palindrome ? "Yes" : "No");
    return 0;
}
