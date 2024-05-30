
class Solution {
  public:
    vector<vector<int>>dp;
    int mod = 1e9+7;
    int recur(string&s1, string&s2, int n, int m) {
        
        if(m == s2.length()) return 1;
        if(n == s1.length()) return 0;
        
        if(dp[n][m] != -1) return dp[n][m];
        
        int temp1 = 0, temp2 = 0;
        if(s1[n] == s2[m]) {
            temp1 = recur(s1, s2, n+1, m+1);
        }
        temp2 = recur(s1, s2, n+1, m);
        return dp[n][m] = (temp1 + temp2)%mod;
    }
    
    int countWays(string s1, string s2) {
        int n = s1.length(), m = s2.length();
        dp.resize(n, vector<int>(m, -1));
        return recur(s1, s2, 0, 0);
    }
};
