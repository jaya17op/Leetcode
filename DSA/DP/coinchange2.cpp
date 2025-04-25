#include <iostream>
#include <vector>
using namespace std;
// Order Matters (Permutation-based)
int cc1(vector<int>& coins, int t) {
    vector<int> dp(t + 1, 0);
    dp[0] = 1; // Base case: Only 1 way to make sum 0
    for (int i = 1; i <= t; i++) {
        for (int coin : coins) {
            if (i >= coin) dp[i] += dp[i - coin];
        }
    }
    return dp[t];
}
// Order Doesn't Matter (Combination-based)
int cc2(vector<int>& coins, int t) {
    vector<int> dp(t + 1, 0);
    dp[0] = 1; // Base case
    for (int coin : coins) { // Process each coin first to ensure unique order
        for (int i = coin; i <= t; i++) {
            dp[i] += dp[i - coin];
        }
    }
    return dp[t];
}
int main() {
    int x;
    cout << "Enter number of test cases: ";
    cin >> x;
    while (x--) {
        int t, n;
        cout << "\nEnter target amount: ";
        cin >> t;

        cout << "Enter number of coins: ";
        cin >> n;
        
        vector<int> coins(n);
        cout << "Enter coin denominations: ";
        for (int i = 0; i < n; i++) {
            cin >> coins[i];
        }
        cout << "Ways (Order Matters): " << cc1(coins, t) << endl;
        cout << "Ways (Order Doesn't Matter): " << cc2(coins, t) << endl;
    }
    return 0;
}