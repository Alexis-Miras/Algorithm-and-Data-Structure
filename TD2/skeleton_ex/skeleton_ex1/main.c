#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "search.h"
#include "utils.h"

int cmpfunc(const void *a, const void *b) {
    int ia = *(int*)a;
    int ib = *(int*)b;
    if (ia < ib) return -1;
    else if (ia > ib) return 1;
    else return 0;
}

int main(void) {

    FILE *f = fopen("../input.txt", "r");
    if (!f) {
        perror("Erreur d'ouverture du fichier");
        return 1;
    }

    int n = 1000;
    int target = 5629;
    int* sort_arr = malloc(sizeof(int)*n);
    int* unsort_arr = malloc(sizeof(int)*n);

    for (int i = 0; i < n; i++) {
        if (fscanf(f, "%d", &sort_arr[i]) != 1) {
            fprintf(stderr, "Erreur de lecture à la ligne %d\n", i + 1);
            fclose(f);
            return EXIT_FAILURE;
        }
        if (fscanf(f, "%d", &unsort_arr[i]) != 1) {
            fprintf(stderr, "Erreur de lecture à la ligne %d\n", i + 1);
            fclose(f);
            return EXIT_FAILURE;
        }
    }
    fclose(f);

    int idx = rand() % n;
    sort_arr[idx] = target;
    unsort_arr[idx] = target;

    qsort(sort_arr, n, sizeof(int), cmpfunc);

    clock_t starting_clock_linear = clock();
    int linear_res = linear_search(unsort_arr, n, target);
    clock_t ending_clock_linear = clock();

    double linear_time = (double)(ending_clock_linear - starting_clock_linear) / CLOCKS_PER_SEC;

    printf("Linear search (%i) = %i, time : %f seconds \n", target, linear_res, linear_time);

    if (is_sorted_nondecreasing(sort_arr, n)) {
        clock_t starting_clock_jump = clock();
        int jump_res = jump_search(sort_arr, n, target);
        clock_t ending_clock_jump = clock();

        clock_t starting_clock_binary = clock();
        int binary_res = binary_search(sort_arr, n, target);
        clock_t ending_clock_binary = clock();

        double jump_time = (double)(ending_clock_jump - starting_clock_jump) / CLOCKS_PER_SEC;
        double binary_time = (double)(ending_clock_binary - starting_clock_binary) / CLOCKS_PER_SEC;

        printf("Jump search (%i) = %i, time : %f seconds \n", target, jump_res, jump_time);
        printf("Binary search (%i) = %i, time : %f seconds \n", target, binary_res, binary_time);
        
        printf("\nRatios of execution times:\n");
        printf("- Linear/Jump: %f\n", linear_time / jump_time);
        printf("- Binary/Jump: %f\n", binary_time / jump_time);
            
    } else {
        printf("Unsorted array \n");
    }

    free(sort_arr);
    free(unsort_arr);

    return 0;
}
