class Solution {
public:
    int mod = 1000000007;

    long long modPow(long long base, long long exp) {
        if (exp == 0) return 1;
        long long value = modPow(base, exp / 2);
        long long result = (value * value) % mod;
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        return result;
    }

    int countGoodNumbers(long long n) {
        long long even = (n + 1) / 2; // even positions (0-based indexing)
        long long odd = n / 2;        // odd positions

        long long forEven = modPow(5, even);
        long long forOdd = modPow(4, odd);

        return (forEven * forOdd) % mod;
    }
};
