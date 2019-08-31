#include <stdio.h>

/**
 * Функция определяет размер строки
 * @param str строка
 * @return размер строки
 */
size_t my_strnlen(const char *str) {
    size_t count = 0;
    while (str[count] != '\0') {
        ++count;
    }
    return count;
}

/**
 * Копирует содержимое второй строки в первую
 * @param str1 первый буфер
 * @param str2 второй буфер
 * @return указатель на первый буфер
 */
char *my_strcpy(char *str1, char *str2) {
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

/**
 * Копирует содержимое второй строки в первую n символов
 * @param dest первый буфер
 * @param src второй буфер
 * @param n количество символов для копирования
 * @return указатель на первый буфер
 */
char *my_strncpy(char *dest, char *src, size_t n) {
    size_t i;
    for (i = 0; i < n && src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    for (; i < n; i++) {
        dest[i] = '\0';
    }
    return dest;
}

/**
 * Объединяет содержимое первой и второй строки
 * @param dest первая строка
 * @param src вторая строка
 * @return указатель на первую строку
 */
char* my_strcat(char *dest, const char *src) {
    size_t i = 0;
    for (; dest[i] != 0; ++i) {
    }
    for (; *src != 0; ++src, ++i) {
        dest[i] = *src;
    }
    dest[i] = 0;
    return dest;
}

/**
 * Объедиянет содержимое первой строки и n символов второй строки
 * @param dest первая строка
 * @param src вторая строка
 * @param n количество символов второй строки
 * @return указатель на первую строку
 */
char* my_strncat(char *dest, const char *src, size_t n) {
    while(*dest) {
        ++dest;
    }
    for (size_t i = 0; i < n && *src != 0; ++i, ++src, ++dest) {
        *dest = *src;
    }
    *dest = 0;
    return dest;
}

int main() {
    char *str = "Sample string";
    char  buf[10] = {0}; // буфер размером меньше строки
    my_strncpy(buf, "Hello", sizeof(buf)-1);
    buf[sizeof(buf) - 1] = '\0';
    printf("%s\n", buf);
    my_strncpy(buf, "Very very long hello", sizeof(buf)-1);
    buf[sizeof(buf) - 1] = '\0';
    printf("%s\n", buf);
    char s1[20];
    char s2[10];
    my_strncpy(s1, "Hello", sizeof(buf)-1);
    s1[sizeof(s1) - 1] = '\0';
    my_strncpy(s2, "Liza", sizeof(buf)-1);
    s2[sizeof(s2) - 1] = '\0';
    my_strncat(s1, s2, 2);
    printf("%s\n", s1);
    //printf("%d", my_strnlen(str1));
    //my_strcpy(str2, str1);
   // printf("%s\n", str2);
    //printf("%s", my_strncpy(str1, str2, 2));
}



