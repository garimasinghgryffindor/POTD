
//Function to find the maximum possible amount of money we can win.
class Solution{
    public: vector<vector<int>> dp;
    
    int help(int arr[], int l, int r) {
        if(l == r) return arr[l];
        if(l > r) return 0;
        
        if(dp[l][r] != -1) return dp[l][r];
        
        int left = arr[l] + min(help(arr, l+2, r), help(arr, l+1, r-1));
        int right = arr[r] + min(help(arr, l+1, r-1), help(arr, l, r-2));
        
        return dp[l][r] = max(left, right);
    }
    
    long long maximumAmount(int n, int arr[]){
        // Your code here
        dp.resize(n, vector<int>(n, -1));
        
        return help(arr, 0, n-1);
    }
};
