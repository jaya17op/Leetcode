#include <bits/stdc++.h>
using namespace std;

// Function to count coin combinations where **order matters** (like permutations)
// e.g., [1, 2] and [2, 1] are considered different
int cc1(int amount, vector<int>& coins) {
    vector<int> dp(amount + 1, 0);
    dp[0] = 1; // Base case: There's 1 way to make amount 0 (use no coins)

    // Iterate over all possible amounts from 1 to 'amount'
    for (int i = 1; i <= amount; i++) {
        for (int coin : coins) {
            if (i >= coin) {
                // Add ways to make (i - coin) because order matters
                dp[i] += dp[i - coin];
            }
        }
    }
    return dp[amount]; // Total ways to make the target amount
}

// Function to count coin combinations where **order doesn't matter** (like combinations)
// e.g., [1, 2] and [2, 1] are considered the same
int cc2(int amount, vector<int>& coins) {
    vector<int> dp(amount + 1, 0);
    dp[0] = 1; // Base case

    // Iterate over coins first, then amount
    // This avoids reusing the same coin in different orders
    for (int coin : coins) {
        for (int i = coin; i <= amount; i++) {
            // Add ways to make (i - coin) using current and previous coins
            dp[i] += dp[i - coin];
        }
    }
    return dp[amount]; // Total distinct ways to make the amount
}

int main() {
    int t;
    cout << "Enter number of test cases: ";
    cin >> t;

    while (t--) {
        int n, amount;
        cout << "\nEnter number of coins: ";
        cin >> n;

        vector<int> coins(n);
        cout << "Enter coin values: ";
        for (int i = 0; i < n; ++i)
            cin >> coins[i];

        cout << "Enter amount: ";
        cin >> amount;
        
        // Output results from both approaches
        cout << "Ways with order (permutations): " << cc1(amount, coins) << endl;
        cout << "Ways without order (combinations): " << cc2(amount, coins) << endl;
    }

    return 0;
}
