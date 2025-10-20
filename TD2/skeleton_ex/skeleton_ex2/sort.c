#include <stdlib.h>
#include "sort.h"
#include "utils.h"

void selection_sort(int *arr, int n) {
    for (int i = 0; i < n-1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < min) {
                min = j;
            }
            if (min != i) swap_int(&arr[i], &arr[min]);
        }
    }
}

void insertion_sort(int *arr, int n) {
    for (int i = 1; i < n-1; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void bubble_sort(int *arr, int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j+1] < arr[j]) swap_int(&arr[j], &arr[j+1]);
        }
    }
}

void merge(int *arr, int *tmp, int l, int m, int r) {
    for (int i = l; i <= r; i++) {
        tmp[i] = arr[i];
    }
    int j = m + 1, i = l;
    for (int k = l; k <= r; k++) {
        if (i > m) arr[k] = tmp[j++];
        else if (j > r) arr[k] = tmp[i++];
        else if (tmp[i] <= tmp[j]) arr[k] = tmp[i++];
        else if (tmp[i] > tmp[j]) arr[k] = tmp[j++];
    }
}

void mergesort_rec(int *arr, int *tmp, int l, int r) {
    int m = (r + l) / 2;
    if (l < r) {
        mergesort_rec(arr, tmp, l, m);
        mergesort_rec(arr, tmp, m + 1, r);
        merge(arr, tmp, l, m, r);
    }
}

void merge_sort(int *arr, int n) {
    if (!arr || n <= 1)
        return;
    int *tmp = (int *)malloc((size_t)n * sizeof(int));
    if (!tmp)
        return;
    mergesort_rec(arr, tmp, 0, n - 1);
    free(tmp);
}

int partition(int *arr, int l, int r) {
    int p = arr[r];
    int idx = l;
    for (int i = l; i < r; i++) {
        if (arr[i] < p) {
            swap_int(&arr[i], &arr[idx]);
            idx++;
        }
    }
    swap_int(&arr[idx], &arr[r]);
    return idx;
}

void quick_sort_rec(int *arr, int l, int r) {
    int p;
    if (l <= r) {
        p = partition(arr, l, r);
        quick_sort_rec(arr, l, p-1);
        quick_sort_rec(arr, p+1, r);
    }
}

void quick_sort(int *arr, int n) {
    if (!arr || n <= 1)
        return;
    quick_sort_rec(arr, 0, n - 1);
}