#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
using namespace std;

class Solution {
public:
    int numRabbits(vector<int>& nums, int total = 0) {
        // Create a hash map to count how many times each answer appears
        unordered_map<int, int> mpp;

        // Count the number of rabbits that gave each answer
        for (int i : nums)
            mpp[i]++;

        /*
            Each rabbit says how many *other* rabbits have the same color.
            So if a rabbit says "k", it means there are (k + 1) rabbits with that color (including itself).
            
            Now, if multiple rabbits say the same number "k", we have to group them into groups of size (k + 1).
            For example:
                - If 3 rabbits say "1" (meaning 2 in a group), we need two groups:
                    ceil(3 / (1 + 1)) = ceil(1.5) = 2 groups
                    So we need 2 * (1 + 1) = 4 rabbits total for these responses.

            This ensures we count the *minimum* number of rabbits required to match all responses.
        */
        for (auto& p : mpp) {
            int answer = p.first;   // the number a rabbit said (how many others it sees with the same color)
            int count = p.second;   // how many rabbits gave this answer

            // Calculate how many full groups we need for this answer
            int groupSize = answer + 1;

            // Divide the count by group size and round up to find the number of groups needed
            int groups = ceil((double)count / groupSize);

            // Add the total number of rabbits needed for these groups
            total += groups * groupSize;
        }

        return total;
    }
};

// Optional main function for testing
int main() {
    Solution sol;
    vector<int> nums = {1, 1, 2}; // Example input: 2 rabbits say "1", 1 rabbit says "2"
    
    cout << "Minimum number of rabbits in the forest: " << sol.numRabbits(nums) << endl;
    // Expected Output: 5
    // Explanation:
    // - Two rabbits say "1" → could be in a group of 2
    // - One rabbit says "2" → implies there are 3 rabbits of that color

    return 0;
}
