class Solution {
  public:
    vector<int> Series(int n) {
        // Code here
        int mod = 1e9+7;
        vector<int>fib(n+1, 0);
        
        fib[1] = 1;
        for(int i = 2; i <= n; i++) {
            fib[i] = (fib[i-1] + fib[i-2])%mod;
        }
        
        return fib;
    }
};
