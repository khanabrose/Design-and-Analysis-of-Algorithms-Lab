#include <stdio.h>
#include <limits.h>
#include <string.h> // Include the string.h header file for memset

#define V 4 // Number of vertices in the graph

// Function to find the minimum cost path using Dynamic Programming
int tsp(int graph[][V], int mask, int pos, int n, int dp[][16]) {
    if (mask == (1 << n) - 1)
        return graph[pos][0];

    if (dp[mask][pos] != -1)
        return dp[mask][pos];

    int ans = INT_MAX;

    // Try all possible next vertices
    for (int city = 0; city < n; city++) {
        if ((mask & (1 << city)) == 0) {
            int newAns = graph[pos][city] + tsp(graph, mask | (1 << city), city, n, dp);
            ans = (ans < newAns) ? ans : newAns;
        }
    }

    return dp[mask][pos] = ans;
}

// Main function
int main() {
    int graph[][V] = {{0, 10, 15, 20},
                      {10, 0, 35, 25},
                      {15, 35, 0, 30},
                      {20, 25, 30, 0}};

    int dp[16][16];
    memset(dp, -1, sizeof(dp));

    printf("Minimum cost of the Travelling Salesman Problem is %d\n", tsp(graph, 1, 0, V, dp));

    return 0;
}
