#include <stdio.h>

// Function to calculate Fibonacci number using recursion
int fibonacci(int n) {
    if (n <= 1)
        return n;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

// Main function
int main() {
    int n = 9; // Find the 9th Fibonacci number
    int result = fibonacci(n);
    printf("The %dth Fibonacci number is: %d\n", n, result);
    return 0;
}
