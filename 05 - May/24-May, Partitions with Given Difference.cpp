class Solution {
  public:
    int MOD = 1e9+7;
    int countPartitions(int n, int d, vector<int>& arr) {
        int sum = 0;
        for(int x: arr) {
            sum += x;
        }
        
        int find_sum = (d + sum)/2;
        if (sum < d || (sum - d) % 2 != 0) {
            return 0;
        }
        
        vector<vector<int>>dp(n+1, vector<int>(sum+1, 0));
        for(int i = 0; i <= n; ++i) {
            dp[i][0] = 1;
        }
        
        for(int i = 1; i <= n; ++i) {
            for(int j = 0; j <= find_sum; ++j) {
                dp[i][j] = dp[i-1][j];
                
                if(j >= arr[i-1]) {
                    dp[i][j] = (dp[i][j] + dp[i-1][j-arr[i-1]])%MOD;
                }
            }
        }   
            
        return dp[n][find_sum];
    }
};
