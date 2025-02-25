#include <iostream>
#include <vector>
using namespace std;

// Function to solve the 0/1 Knapsack Problem using Dynamic Programming
int knapsack(int C, vector<int> &W, vector<int> &P, int n)
{
    // Create a DP table where dp[i][w] stores the max profit for first 'i' items and capacity 'w'
    vector<vector<int>> dp(n + 1, vector<int>(C + 1, 0));

    // Fill the DP table iteratively
    for (int i = 1; i <= n; i++)
    { // Iterate over each item
        for (int w = 1; w <= C; w++)
        {                                                                         // Iterate over each weight capacity
            if (W[i - 1] <= w)                                                    // If the item can fit in the current capacity
                dp[i][w] = max(P[i - 1] + dp[i - 1][w - W[i - 1]], dp[i - 1][w]); // Include or exclude the item
            else
                dp[i][w] = dp[i - 1][w]; // If item weight exceeds capacity, exclude it
        }
    }
    return dp[n][C]; // Return the maximum profit for 'n' items and knapsack capacity 'C'
}

int main()
{
    // Profit values for items
    vector<int> P = {15, 25, 13, 23};
    // Corresponding weight values for items
    vector<int> W = {2, 6, 12, 9};
    int C = 20;       // Knapsack capacity
    int n = P.size(); // Number of items

    // Call knapsack function and print the maximum profit
    cout << "Maximum Profit: " << knapsack(C, W, P, n) << endl;
    return 0;
}
