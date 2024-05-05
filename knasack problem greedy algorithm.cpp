#include <stdio.h>

// Structure to represent an item
struct Item {
    int value;
    int weight;
};

// Function to calculate maximum value using greedy approach
int knapsackGreedy(struct Item items[], int n, int capacity) {
    // Sort items by value-to-weight ratio in descending order
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            double ratio1 = (double)items[i].value / items[i].weight;
            double ratio2 = (double)items[j].value / items[j].weight;
            if (ratio1 < ratio2) {
                struct Item temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }

    int totalValue = 0;
    int currentWeight = 0;

    // Select items greedily until the knapsack is full
    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= capacity) {
            currentWeight += items[i].weight;
            totalValue += items[i].value;
        } else {
            // Fractional knapsack: Uncomment below lines for fractional knapsack
            // double remainingCapacity = capacity - currentWeight;
            // totalValue += remainingCapacity * (double)items[i].value / items[i].weight;
            break; // Stop if knapsack is full
        }
    }

    return totalValue;
}

int main() {
    struct Item items[] = {{60, 10}, {100, 20}, {120, 30}};
    int n = sizeof(items) / sizeof(items[0]);
    int capacity = 50;
    int maxValue = knapsackGreedy(items, n, capacity);
    printf("Maximum value that can be obtained: %d\n", maxValue);
    return 0;
}
