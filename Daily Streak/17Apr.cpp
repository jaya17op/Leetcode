#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] == nums[j] && (i * j) % k == 0) {
                    ans++;
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;

    // Example input
    vector<int> nums = {3, 1, 2, 2, 2, 1, 3};
    int k = 2;

    int result = solution.countPairs(nums, k);
    cout << "Number of valid pairs: " << result << endl;

    return 0;
}
