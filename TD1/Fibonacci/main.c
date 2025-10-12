#include <stdio.h>
#include <time.h>
#include "fibonacci.h"

int main() {

   int n = 42;
   long long int DP_fib[n+1];

   for (int i = 0; i < n+1; i++) {
      DP_fib[i] = -1;
   }

   clock_t starting_clock_naive = clock();

   long long int res_naive = fibonacci_naive(n);

   clock_t ending_clock_naive = clock();


   clock_t starting_clock_DP = clock();

   long long int res_DP = fibonnacci_DP(n, DP_fib);

   clock_t ending_clock_DP = clock();

   double naive_time = (double)(ending_clock_naive - starting_clock_naive) / CLOCKS_PER_SEC;
   double DP_time = (double)(ending_clock_DP - starting_clock_DP) / CLOCKS_PER_SEC;

   printf("Naive fibonacci(%i) = %lli, time : %f seconds \n", n, res_naive, naive_time);
   printf("DP fibonacci(%i) = %lli, time : %f seconds \n", n, res_DP, DP_time);

   return 0;

}