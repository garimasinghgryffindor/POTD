class Solution{
		
	public:
	vector<vector<int>> dp;
	int recur(int a[], int b[], int x, int y) {
	    if(x < 0 || y < 0) return 0;
	    if(y > x) return 0;
	    
	    if(dp[x][y] != -1) return dp[x][y];
	    
	    if(x == 0 && y == 0) {
	        return dp[x][y] = a[0]*b[0];
	    }
	    
	    int res = 0;
	    
	    // either will take
	    int sum = recur(a, b, x-1, y-1);
	    res += sum + a[x]*b[y];
	    
	    // or will not take
	    int sum1 = recur(a, b, x-1, y);
	    res = max(sum1, res);
	    
	    return dp[x][y] = res;
	}
	
	int maxDotProduct(int n, int m, int a[], int b[]) 
	{ 
		// Your code goes here
		dp.resize(n+1, vector<int>(m+1, 0));
// 		int res = recur(a, b, n-1, m-1);
		
		dp[1][1] = a[0]*b[0];
		
		for(int i = 1; i <= m; i++) {
		    for(int j = i; j <= n-(m-i); j++) {
		        if(i == 1 && j == 1) continue;
		        
		        int res = 0;
		        // will take
		        int sum = dp[j-1][i-1];
		        res += sum + a[j-1]*b[i-1];
		      //  cout<<res<<"  ";
		        
		        // will not take
		        int sum1 = dp[j-1][i];
		        res = max(res, sum1);
		        
		        dp[j][i] = res;
		      //  cout<<res<<"  ";
		    }
		}
		
		return dp[n][m];
	} 
};
