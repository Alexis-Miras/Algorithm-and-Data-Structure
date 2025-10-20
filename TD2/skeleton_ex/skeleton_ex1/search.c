#include <math.h>
#include <stdio.h>
#include "search.h"
#include "utils.h"

int linear_search(int *arr, int n, int target) {
    
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) return i;
    }

    return -1;
}

int jump_search(int *arr, int n, int target) {
    int jump = sqrt(n);
    int step = jump;
    int prev = 0;

    // step < n
    while (arr[min_int(step, n)-1] < target) {
        prev = step;
        step += jump;
        if (prev >= n) return -1;
    }

    for (int i = prev; i < min_int(step, n); i++) {
        if (arr[i] == target) return i;
    }

        /*
    for (int i = step; i < n; i += step) {
        int next = i + step;
        if (next > n) next = n;

        if (arr[next - 1] >= target) {
            for (int j = i - step; j < next && j < n; j++) {
                if (arr[j] == target) return j;
            }
        } else {
            return -1;
        }
    }
        */
    
    return -1;
}

int binary_search(int *arr, int n, int target) {
    int low = 0;
    int high = n - 1;

    while(low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == target) return mid;
        if (arr[mid] < target) low = mid + 1;
        else high = mid -1;
    }

    return -1;
}