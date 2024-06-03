class Solution {
  public:
    int numberOfConsecutiveOnes(int n) {
        int MOD = 1e9+7;
        if (n == 1 || n == 2) {
            return 1;
        }
        long long a = 1, b = 1;
        long long res = 1;
        for (int i = 3; i <= n; i++) {
            long long c = (a + b) % MOD;
            a = b;
            b = c;
            res = (res * 2 + a) % MOD;
        }
        return (int)res;
    }
};
