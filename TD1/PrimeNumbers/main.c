#include <stdio.h>
#include <time.h>
#include "prime_numbers.h"

int main() {
    int n = 99;

    clock_t starting_clock_naive = clock();

    int res_naive = prime_numbers_naive(n);

    clock_t ending_clock_naive = clock();

    double naive_time = (double)(ending_clock_naive - starting_clock_naive) / CLOCKS_PER_SEC;

    clock_t starting_clock_greedy = clock();

    int res_greedy = prime_numbers_greddy(n);

    clock_t ending_clock_greedy = clock();

    double greedy_time = (double)(ending_clock_greedy - starting_clock_greedy) / CLOCKS_PER_SEC;

    printf("Naive prime numbers(%i) = %i, time : %f seconds \n", n, res_naive, naive_time);
    printf("Greedy/Sieve prime numbers(%i) = %i, time : %f seconds \n", n, res_greedy, greedy_time);

    return 0;
}