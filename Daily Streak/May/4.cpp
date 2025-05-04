class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        vector <int> count(100, 0);
        for(int i=0;i<dominoes.size();i++){
            int maxi = max(dominoes[i][0], dominoes[i][1]);
            int mini = min(dominoes[i][0], dominoes[i][1]);
            int x = maxi*10 + mini;
            count[x]++;
        }
        long long ans = 0;
        for(int i:count){
            if(i > 1) ans += i*(i-1)/2;
        }
        return ans;
    }
};