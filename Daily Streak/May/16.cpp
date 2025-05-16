class Solution {
    public:
        vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
            int n = words.size();
            if (n == 0) return {};
            auto pack = [&](const string &w) {
                uint64_t code = 0;
                for (int i = 0; i < (int)w.size(); ++i) {
                    code |= (uint64_t(w[i] - 'a') << (5 * i));
                }
                return code;
            };
            vector<uint64_t> codes(n);
            for (int i = 0; i < n; ++i) {
                codes[i] = pack(words[i]);
            }
            vector<int> dp(n, 1), prev(n, -1);
            int max_len = 1, max_idx = 0;
            vector<vector<unordered_map<uint64_t, vector<int>>>> patterns_by_len(11);
            for (int i = 0; i < n; ++i) {
                int L = words[i].size();
                int g  = groups[i];
                uint64_t code_i = codes[i];
                if (patterns_by_len[L].empty()) {
                    patterns_by_len[L].resize(L);
                    for (int j = 0; j < L; ++j) {
                        patterns_by_len[L][j].reserve(n);
                    }
                }
                auto &buckets = patterns_by_len[L];
                int best_len = 1, best_prev = -1;
                for (int j = 0; j < L; ++j) {
                    uint64_t mask = ~(uint64_t(31) << (5 * j));
                    uint64_t pat  = code_i & mask;
                    auto it = buckets[j].find(pat);
                    if (it != buckets[j].end()) {
                        for (int k : it->second) {
                            if (groups[k] != g && dp[k] + 1 > best_len) {
                                best_len  = dp[k] + 1;
                                best_prev = k;
                            }
                        }
                    }
                }
                dp[i]   = best_len;
                prev[i] = best_prev;
                if (best_len > max_len) {
                    max_len = best_len;
                    max_idx = i;
                }
                for (int j = 0; j < L; ++j) {
                    uint64_t mask = ~(uint64_t(31) << (5 * j));
                    uint64_t pat  = code_i & mask;
                    buckets[j][pat].push_back(i);
                }
            }
            vector<string> res;
            for (int cur = max_idx; cur != -1; cur = prev[cur]) {
                res.push_back(words[cur]);
            }
            reverse(res.begin(), res.end());
            return res;
        }
    };