#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"
#include "utils.h"

int main(void) {
    int n = 25000;
    int* arr1 = malloc(sizeof(int)*n);
    int* arr2 = malloc(sizeof(int)*n);
    int* arr3 = malloc(sizeof(int)*n);
    int* arr4 = malloc(sizeof(int)*n);
    int* arr5 = malloc(sizeof(int)*n);

    srand(time(NULL));

    for (int i = 0; i < n; i++) {
        arr1[i] = rand() % 10000;
        arr2[i] = rand() % 10000;
        arr3[i] = rand() % 10000;
        arr4[i] = rand() % 10000;
        arr5[i] = rand() % 10000;
    }

    clock_t starting_clock_selection = clock();
    selection_sort(arr1, n);
    clock_t ending_clock_selection = clock();

    clock_t starting_clock_insertion = clock();
    insertion_sort(arr2, n);
    clock_t ending_clock_insertion = clock();

    clock_t starting_clock_bubble = clock();
    bubble_sort(arr3, n);
    clock_t ending_clock_bubble = clock();

    clock_t starting_clock_merge = clock();
    merge_sort(arr4, n);
    clock_t ending_clock_merge = clock();

    clock_t starting_clock_quick = clock();
    quick_sort(arr5, n);
    clock_t ending_clock_quick = clock();

    double selection_time = (double)(ending_clock_selection - starting_clock_selection) / CLOCKS_PER_SEC;
    double insertion_time = (double)(ending_clock_insertion - starting_clock_insertion) / CLOCKS_PER_SEC;
    double bubble_time = (double)(ending_clock_bubble - starting_clock_bubble) / CLOCKS_PER_SEC;
    double merge_time = (double)(ending_clock_merge - starting_clock_merge) / CLOCKS_PER_SEC;
    double quick_time = (double)(ending_clock_quick - starting_clock_quick) / CLOCKS_PER_SEC;

    printf("Sorting %i random values:\n", n);
    printf("Selection sort time: %f seconds \n", selection_time);
    printf("Insertion sort time: %f seconds \n", insertion_time);
    printf("Bubble sort time: %f seconds \n", bubble_time);
    printf("Merge sort time: %f seconds \n", merge_time);
    printf("Quick sort time: %f seconds \n", quick_time);

    free(arr1);
    free(arr2);
    free(arr3);
    free(arr4);
    free(arr5);

    return 0;
}
