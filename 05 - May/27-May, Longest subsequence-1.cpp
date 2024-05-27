
class Solution {
  public:
    
    int longestSubseq(int n, vector<int> &a) {
        unordered_map<int, int> dp;
        int ans = 0;

        for (int i = 0; i < n; ++i) {
            int x = a[i];
            int len1 = dp[x - 1] + 1;
            int len2 = dp[x + 1] + 1;
            dp[x] = max(dp[x], max(len1, len2));
            ans = max(ans, dp[x]);
        }

        return ans;
    }
};
