#include <stdio.h>

size_t my_strnlen(const char *str) {
    size_t count = 0;
    while (str[count] != '\0') {
        ++count;
    }
    return count;
}

char *my_strcpy(char *str1, const char *str2) {
    size_t i = 0;
    while (1) {
        str1[i] = str2[i];
        if (str2[i] == '\0') {
            break;
        }
        i++;
    }
    return str1;
}

char *my_strncpy(char *dest, const char *src, size_t n) {
    size_t i;
    for (i = 0; i < n && src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    for (; i < n; i++) {
        dest[i] = '\0';
    }
    return dest;
}

int main() {
    char *str1 = "Hello";
    char *str2[40];
    //printf("%d", my_strnlen(str1));
    my_strcpy(str2, str1);
    printf("%s", str2);
    my_strncpy(str1, str2, 3);
    printf("%s", str1);
}



