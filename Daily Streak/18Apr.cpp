#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    using info = pair<int, char>;  // Pair of (frequency, digit)

    // Converts the frequency vector to a string
    string str(const vector<info>& fc) {
        string ans;
        for (const auto& p : fc) {
            ans += to_string(p.first);
            ans.push_back(p.second);
        }
        return ans;
    }

    // Recursive function to generate frequency vector for nth term
    vector<info> freq(int n) {
        if (n == 2) return {{1, '1'}}; // Base case: 2nd term is "11"
        auto fc = freq(n - 1);         // Recursive call for previous term
        string s1 = str(fc);           // Get the string from frequency vector

        int sz = s1.size();
        char c = s1[0];
        vector<info> ans = {{1, c}};
        for (int i = 1; i < sz; i++) {
            if (s1[i] == c) {
                ans.back().first++;    // Increase frequency count
            } else {
                ans.emplace_back(1, s1[i]);  // New character encountered
                c = s1[i];
            }
        }
        return ans;
    }

    // Main function to return the nth term of count and say sequence
    string countAndSay(int n) {
        if (n == 1) return "1";
        auto fc = freq(n);
        return str(fc);
    }
};

int main() {
    Solution solution;
    int n;
    cout << "Enter n: ";
    cin >> n;
    string result = solution.countAndSay(n);
    cout << "The " << n << "th term in the count-and-say sequence is: " << result << endl;
    return 0;
}
