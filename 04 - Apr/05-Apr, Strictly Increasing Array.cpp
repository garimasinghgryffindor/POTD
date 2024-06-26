class Solution {
  public:

    int min_operations(vector<int>& nums) {
        // Code here
        // Longest increasing subsequence
        int n = nums.size();
        int res = 1;
        vector<int> dp(n, 1);
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] - nums[j] >= i-j) {
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
            
            res = max(res, dp[i]);
        }
        return n-res;
    }
};
