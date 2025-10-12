#include "fibonacci.h"

long long int fibonnacci_DP(int n, long long int DP_fib[]) {
    if(n <= 1) {
        return n;
    }
    if (DP_fib[n] != -1) {
        return DP_fib[n];
    }
    DP_fib[n] = fibonnacci_DP(n - 1, DP_fib) + fibonnacci_DP(n - 2, DP_fib);
    return DP_fib[n];
}

long long int fibonacci_naive(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibonacci_naive(n - 1) + fibonacci_naive(n - 2);
    }
}