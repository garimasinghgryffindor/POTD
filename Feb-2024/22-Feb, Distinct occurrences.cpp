/*You are required to complete this method*/

class Solution
{
    int mod = 1e9 + 7;
    public:
    
    int recur(string&s, string&t, int i, int j, vector<vector<int>>&mem) {
        if(mem[i][j] != -1) return mem[i][j];
        
        if(j == t.length()) {
            return 1;
        }
        if(i == s.length()) return 0;
        
        int res = 0;
        if(s[i] == t[j]) {
            res = (res + (long)recur(s, t, i+1, j+1, mem))%mod;
        }
        res = (res + (long)recur(s, t, i+1, j, mem))%mod;

        return mem[i][j] = res;
    }
    
    int subsequenceCount(string s, string t)
    {
        int m = s.length();
        int n = t.length();

        // Create a 2D DP table
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // Base case: If the target string is empty, there is one subsequence (empty string)
        for (int i = 0; i <= m; ++i)
        {
            dp[i][n] = 1;
        }

        // Fill the DP table iteratively
        for (int i = m - 1; i >= 0; --i)
        {
            for (int j = n - 1; j >= 0; --j)
            {
                // If the characters match, consider both including and excluding the current character
                if (s[i] == t[j])
                {
                    dp[i][j] = (dp[i + 1][j + 1] + dp[i + 1][j]) % mod;
                }
                // If characters do not match, consider excluding the current character
                else
                {
                    dp[i][j] = dp[i + 1][j];
                }
            }
        }

        return dp[0][0];
    }
};
 
