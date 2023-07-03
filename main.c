#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int verifyString(char *string, char c, int size) {
    int v = 1;
    string[size] = '\0';
    for (int i = 0 ; i < size ; i++) {
        if (c == string[i]){
            v = 0;
        }
    }
    return v;
}


int lengthOfLongestSubstring(char * s){
    int count = 0, k = 0, i = 0, result = 0;
    char *str = (char*)malloc(sizeof(char) * strlen(s));

    while (i < strlen(s)) {
        if (verifyString(str, s[i], k) == 1) {
            //printf("adiciona letra '%c' a string '%s'\n", s[i], str);
            str[k] = s[i];
            k++;
            i++;
            if (k >= result)
                result = k;
        }
        else {
            count++;
            i = count;
            k = 0;
        }
    }
    return result;
}

int main () {
    printf("%d\n", lengthOfLongestSubstring("abcabcbb"));
}

