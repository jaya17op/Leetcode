#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Count the number of pairs (i, j) where i < j and nums[i] + nums[j] >= comp
    long long countAtLeast(vector<int>& nums, long long comp, long long ans = 0) {
        int i = 0, j = nums.size() - 1;
        while (i < j) {
            if (nums[i] + nums[j] >= comp) {
                ans += (j - i);
                --j;
            } else {
                ++i;
            }
        }
        return ans;
    }

    // Count the number of fair pairs where lower <= nums[i] + nums[j] <= upper
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        return countAtLeast(nums, lower) - countAtLeast(nums, upper + 1);
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 7, 3, 5};
    int lower = 8;
    int upper = 10;

    long long result = sol.countFairPairs(nums, lower, upper);
    cout << "Number of fair pairs: " << result << endl;

    return 0;
}
