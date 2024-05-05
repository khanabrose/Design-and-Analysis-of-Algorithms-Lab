#include <stdio.h>

// Function to calculate the value of the recurrence relation using the Master Theorem
int masterTheorem(int a, int b, int k, int n) {
    // Base case: T(1) = 1
    if (n == 1)
        return 1;

    // Calculate the value of c in the recurrence relation T(n) = a * T(n/b) + f(n)
    int c = 1;
    if (k == 0)
        c = a;
    else if (k > 0)
        c = a * k;

    // Calculate the value of n^(log_b(a))
    int power = 1;
    int base = n / b;
    for (int i = 0; i < c; i++)
        power *= base;

    // Calculate the value of f(n)
    int f_n = n; // For simplicity, assume f(n) = n

    // Calculate the value of T(n)
    int T_n = c * masterTheorem(a, b, k, base) + f_n * power;

    return T_n;
}

// Main function
int main() {
    int a = 2; // Number of subproblems
    int b = 2; // Factor by which the problem size is reduced
    int k = 0; // Constant factor multiplying T(n/b)
    int n = 8; // Size of the problem

    int result = masterTheorem(a, b, k, n);
    printf("The value of T(%d) is: %d\n", n, result);

    return 0;
}
