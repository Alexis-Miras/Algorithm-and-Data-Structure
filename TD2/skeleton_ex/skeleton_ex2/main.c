#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"
#include "utils.h"

#include <string.h>

int main(void) {

    FILE *f = fopen("../input.txt", "r");
    if (!f) {
        perror("Erreur d'ouverture du fichier");
        return 1;
    }

    int n = 25000;
    int* read_arr = malloc(sizeof(int)*n);
    int* selection_arr = malloc(sizeof(int)*n);
    int* insertion_arr = malloc(sizeof(int)*n);
    int* bubble_arr = malloc(sizeof(int)*n);
    int* merge_arr = malloc(sizeof(int)*n);
    int* quick_arr = malloc(sizeof(int)*n);

    for (int i = 0; i < n; i++) {
        if (fscanf(f, "%d", &read_arr[i]) != 1) {
            fprintf(stderr, "Erreur de lecture à la ligne %d\n", i + 1);
            fclose(f);
            return EXIT_FAILURE;
        }
    }
    fclose(f);

    memcpy(selection_arr, read_arr, n * sizeof(int));
    memcpy(insertion_arr, read_arr, n * sizeof(int));
    memcpy(bubble_arr, read_arr, n * sizeof(int));
    memcpy(merge_arr, read_arr, n * sizeof(int));
    memcpy(quick_arr, read_arr, n * sizeof(int));


    clock_t starting_clock_selection = clock();
    selection_sort(selection_arr, n);
    clock_t ending_clock_selection = clock();

    clock_t starting_clock_insertion = clock();
    insertion_sort(insertion_arr, n);
    clock_t ending_clock_insertion = clock();

    clock_t starting_clock_bubble = clock();
    bubble_sort(bubble_arr, n);
    clock_t ending_clock_bubble = clock();

    clock_t starting_clock_merge = clock();
    merge_sort(merge_arr, n);
    clock_t ending_clock_merge = clock();

    clock_t starting_clock_quick = clock();
    quick_sort(quick_arr, n);
    clock_t ending_clock_quick = clock();

    double selection_time = (double)(ending_clock_selection - starting_clock_selection) / CLOCKS_PER_SEC;
    double insertion_time = (double)(ending_clock_insertion - starting_clock_insertion) / CLOCKS_PER_SEC;
    double bubble_time = (double)(ending_clock_bubble - starting_clock_bubble) / CLOCKS_PER_SEC;
    double merge_time = (double)(ending_clock_merge - starting_clock_merge) / CLOCKS_PER_SEC;
    double quick_time = (double)(ending_clock_quick - starting_clock_quick) / CLOCKS_PER_SEC;

    FILE *f_out_s = fopen("output_selection.txt", "w");
    FILE *f_out_i = fopen("output_insertion.txt", "w");
    FILE *f_out_b = fopen("output_bubble.txt", "w");
    FILE *f_out_m = fopen("output_merge.txt", "w");
    FILE *f_out_q = fopen("output_quick.txt", "w");

    if (!f_out_i || !f_out_s || !f_out_b || !f_out_m || !f_out_q) {
        perror("Erreur ouverture output.txt");
        return EXIT_FAILURE;
    }

    for (int i = 0; i < n; i++) {
        fprintf(f_out_s, "%d\n", selection_arr[i]);
        fprintf(f_out_i, "%d\n", insertion_arr[i]);
        fprintf(f_out_b, "%d\n", bubble_arr[i]);
        fprintf(f_out_m, "%d\n", merge_arr[i]);
        fprintf(f_out_q, "%d\n", quick_arr[i]);
    }

    fclose(f_out_s);
    fclose(f_out_i);
    fclose(f_out_b);
    fclose(f_out_m);
    fclose(f_out_q);

    free(read_arr);
    free(selection_arr);
    free(insertion_arr);
    free(bubble_arr);
    free(merge_arr);
    free(quick_arr);


    printf("Sorting %i random values:\n", n);
    printf("- Selection sort time: %f seconds \n", selection_time);
    printf("- Insertion sort time: %f seconds \n", insertion_time);
    printf("- Bubble sort time: %f seconds \n", bubble_time);
    printf("- Merge sort time: %f seconds \n", merge_time);
    printf("- Quick sort time: %f seconds \n", quick_time);

    printf("\nRatios of execution times:\n");
    printf("- Selection/Bubble: %f\n", selection_time / bubble_time);
    printf("- Insertion/Bubble: %f\n", insertion_time / bubble_time);
    printf("- Merge/Bubble: %f\n", merge_time / bubble_time);
    printf("- Quick/Bubble: %f\n", quick_time / bubble_time);


    return 0;
}
