#include <stdlib.h>
#include "prime_numbers.h"

int prime_numbers_naive(int n) {
    int count = 0;
    int is_prime;

    if (n <= 1) {
        return count;
    }

    for (int i = 2; i < n; i++) {
        is_prime = 1;
        for (int j = 2; j*j <= i; j++) {
            if (i % j == 0) {
                is_prime = 0;
            }
        }
        if (is_prime != 0) {
            count++;
        }
    }
    return count;
}

int prime_numbers_greddy(int n) {
    int count = 0;

    if (n <= 1) {
        return count;
    }

    int* is_visited = malloc(sizeof(int)*n);
    for (int i = 0; i < n; i++) {
        is_visited[i] = 0;
    }
    is_visited[0] = 1;
    is_visited [1] = 1;

    for (int i = 0; i*i < n; i++) {
        if (is_visited[i] != 1) {
            for (int j = i*i; j < n; j += i) {
                is_visited[j] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (is_visited[i] == 0) {
            count++;
        }
    }
    
    
    return count;
}
