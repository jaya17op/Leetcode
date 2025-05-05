const int mod=1e9+7;
unsigned a[1001]={1, 1, 2};
class Solution {
public:
    int numTilings(int n) {
        if (a[n]!=0) return a[n];
        return a[n]=(numTilings(n-1)*2ULL+numTilings(n-3))%mod;
    }
};