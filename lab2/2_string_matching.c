#include <stdio.h>
#include <string.h>

void stringMatch(char *text, char *pattern) {
    int textLen = strlen(text);
    int patternLen = strlen(pattern);
    for (int i = 0; i <= textLen - patternLen; i++) {
        int j;
        for (j = 0; j < patternLen; j++) {
            if (text[i + j] != pattern[j]) {
                break;
            }
        }
        if (j == patternLen) {
            printf("Pattern found at index %d\n", i);
        }
    }
}

int main() {
    char text[] = "ABABDABACDABABCABAB";
    char pattern[] = "ABABCABAB";
    stringMatch(text, pattern);
    return 0;
}
