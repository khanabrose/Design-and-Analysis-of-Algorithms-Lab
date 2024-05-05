#include <stdio.h>
#include <limits.h>

// Function to find the minimum number of multiplications needed to multiply the chain of matrices
int matrixChainOrder(int p[], int n) {
    int m[n][n];
    int i, j, k, L, q;

    // Cost is 0 when multiplying one matrix.
    for (i = 1; i < n; i++)
        m[i][i] = 0;

    // L is chain length.
    for (L = 2; L < n; L++) {
        for (i = 1; i < n - L + 1; i++) {
            j = i + L - 1;
            m[i][j] = INT_MAX;
            for (k = i; k <= j - 1; k++) {
                // q = cost/scalar multiplications
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                    m[i][j] = q;
            }
        }
    }

    return m[1][n - 1];
}

// Main function
int main() {
    int arr[] = {10, 20, 30, 40, 30}; // Matrix dimensions: 10x20, 20x30, 30x40, 40x30
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Minimum number of multiplications needed: %d\n", matrixChainOrder(arr, size));
    return 0;
}
