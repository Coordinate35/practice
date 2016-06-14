#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int kmp(char* s, char* target) {
    int target_length = strlen(target);
    int s_length = strlen(s);
    int *p;
    int i, j;
    p = (int*)malloc(target_length * sizeof(int));
    p[0] = -1;
    j = -1;
    for (i = 1; i < target_length; i++) {
        while ((j > -1) && (target[j + 1] != target[i])) {
            j = p[j];
        }
        if (target[i] == target[j + 1]) {
            j += 1;
        }
        p[i] = j;
    }
    j = -1;
    for (i = 0; i < s_length; i++) {
        while ((j > -1) && (s[i] != target[j + 1])) {
            j = p[j];
        }
        if (target[j + 1] == s[i]) {
            j += 1;
        }
        if (target_length - 1 == j) {
            return i - target_length + 1;
        }
    }
}

int main() {
    char s[] = "i Coordinate35";
    char target[] = "inate";
    int index = kmp(s, target);
    printf("%d\n", index);
    return 0;
}