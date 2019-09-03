#include <stdbool.h>
#include <stdio.h>
#include <math.h>

typedef bool (*predicate) (int);

bool is_even(int number) {
    return number % 2 == 0;
}

bool is_prime(int number) {
    if(number % 2 == 0) {
        return false;
    }
    if(number == 1) {
        return true;
    }
    double count = sqrt(number);
    for (int i = 2; i <= count; ++i) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}

/*int function(const int* const data, predicate pred) {
    int countElements = sizeof(data) / sizeof(*data);
    int *p;
    int count=0;
    for(p=data;p<&data+1;p++)
        count++;
    for(int i = 0; i < count; ++i) {
        if(pred(data[i])) {
            return i;
        }
    }
    return -1;
}
 */