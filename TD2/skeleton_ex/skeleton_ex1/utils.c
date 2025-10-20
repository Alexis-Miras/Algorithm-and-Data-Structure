#include "utils.h"

bool is_sorted_nondecreasing(int *arr, int n) {
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i-1]) return false;
    }
    return true;
}

int min_int(int a, int b) {
    if (a < b) return a;
    else return b;
}