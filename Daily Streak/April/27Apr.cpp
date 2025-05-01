#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < nums.size() - 2; i++) {
            if ((nums[i] + nums[i + 2]) * 2 == nums[i + 1])
                res++;
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums;

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter the elements:" << endl;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        nums.push_back(temp);
    }

    int result = sol.countSubarrays(nums);
    cout << "Number of subarrays: " << result << endl;

    return 0;
}
