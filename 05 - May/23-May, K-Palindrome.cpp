// MEMOIZATION-> TLE
class Solution{
public:
    int recur(string str, int l, int r, vector<vector<int>>&dp) {
        if(l >= r) return 0;
        if(dp[l][r] != -1) return dp[l][r];
        
        int ans = 0;
        if(str[l] == str[r]) {
            ans = recur(str, l+1, r-1, dp);
        } else {
            ans = 1 + recur(str, l+1, r, dp);
            ans = min(ans, 1 + recur(str, l, r-1, dp));
        }
        return dp[l][r] = ans;
    }
    
    int kPalindrome(string str, int n, int k)
    {
        vector<vector<int>>dp(n, vector<int>(n, -1));
        int minRemovals = recur(str, 0, n-1, dp);
        return minRemovals <= k;
    }
};


// TABULATION
// User function Template for C++

class Solution{
public:
    int kPalindrome(string str, int n, int k)
    {
        vector<vector<int>>dp(n, vector<int>(n, 0));
        
        for(int len = 2; len <= n; len++) {
            for(int i = 0; i <= n-len; i++) {
                int j = i + len - 1;
                if(str[i] == str[j]) {
                    dp[i][j] = dp[i+1][j-1];
                } else {
                    dp[i][j] = 1 + min(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        
        int minRemovals = dp[0][n-1];
        return minRemovals <= k;
    }
};
