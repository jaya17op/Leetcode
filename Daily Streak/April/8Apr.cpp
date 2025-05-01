class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size(); 
        unordered_set<int> s;       // To keep track of unique elements (avoiding duplicates)
        int i = 0 ;
        // Step 1: Traverse the array from the end (right to left)
        for (i = n - 1; i >= 0; i--) {
            if (s.find(nums[i]) != s.end()) break;  // Stop if a duplicate is found
            s.insert(nums[i]);                     // Insert unique elements into the set
        }
        // Step 2: Calculate the minimum number of operations
        if ((i + 1) % 3 == 0) return (i + 1) / 3;  // If the length of the distinct part is divisible by 3
        return (i + 1) / 3 + 1;                   // Otherwise, add 1 more operation for the leftover elements
    }
};
