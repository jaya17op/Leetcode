class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        unordered_map<int, long long> prefixCount;
        prefixCount[0] = 1;  // To handle case when prefix itself is interesting
        
        long long count = 0;
        int currentPrefix = 0;

        for (int num : nums) {
            // Check if current number satisfies the condition
            if (num % modulo == k) {
                currentPrefix++;
            }

            currentPrefix %= modulo;
            int target = (currentPrefix - k + modulo) % modulo;

            // If we've seen a prefix with (prefix % modulo == target), count it
            if (prefixCount.find(target) != prefixCount.end()) {
                count += prefixCount[target];
            }

            // Record the current prefix modulo count
            prefixCount[currentPrefix]++;
        }

        return count;
    }
};