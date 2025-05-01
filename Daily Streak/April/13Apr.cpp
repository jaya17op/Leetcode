class Solution {
public:
    const long long MOD = 1'000'000'007;

    long long modPow(long long base, long long exp) {
        long long result = 1;
        while (exp > 0) {
            if (exp % 2 == 1) result = (result * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return result;
    }

    int countGoodNumbers(long long n) {
        long long evenCount = (n + 1) / 2; // positions for even digits (0, 2, 4, ...)
        long long oddCount = n / 2;        // positions for prime digits (1, 3, 5, ...)
        long long evenPart = modPow(5, evenCount);
        long long oddPart = modPow(4, oddCount);
        return (int)((evenPart * oddPart) % MOD);
    }
};
