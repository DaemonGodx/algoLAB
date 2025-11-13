//Name: Pritam Shaw
//Roll : 2024UG3011  sec:B
//subject: Algorithm lab(CS-2107/CD-2107)
//Experiment-6 Task-1-Implementation of 0 1 knapsack 

#include <bits/stdc++.h>
using namespace std;

int knapsack01(int W, vector<int>& wt, vector<int>& val, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (wt[i - 1] <= w)
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }
    return dp[n][W];
}

int main() {
    int n, W;
    cout << "Enter number of items: ";
    cin >> n;
    vector<int> wt(n), val(n);

    cout << "Enter values: ";
    for (int i = 0; i < n; i++) cin >> val[i];
    cout << "Enter weights: ";
    for (int i = 0; i < n; i++) cin >> wt[i];

    cout << "Enter knapsack capacity: ";
    cin >> W;

    cout << "Maximum value in 0/1 Knapsack = " << knapsack01(W, wt, val, n) << endl;
    return 0;
}