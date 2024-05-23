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


