
class Solution {
  public:
    vector<int> getPrimes(int n) {
        bool prime[n + 2];
        memset(prime, true, sizeof(prime));
        prime[0] = false;
        prime[1] = false;
        
        for(int i = 2; i*i <= n; i++) {
            if(prime[i]) {
                for(int j = i*i; j <= n; j+=i) {
                    prime[j] = false;
                }
            }
        }
        
        for(int i = 2; i <= n/2; i++) {
            if(prime[i] && prime[n-i]) {
                return {i, n-i};
            }
        }
        
        return {-1, -1};
    }
};
