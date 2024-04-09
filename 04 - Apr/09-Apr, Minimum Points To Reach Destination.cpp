class Solution{

	public:
	int ans = INT_MAX;
	void recur(vector<vector<int>>&points, int x, int y, int&m, int&n, int sum, int points_) {
	    if(x == m || y == n) return;
	    if(x == m-1 && y == n-1) {
	        if(sum + points[x][y] <= 0) {
	            points_ = points_ + abs(sum+points[x][y]) + 1;
	        }
	        ans = min(ans, points_);
	        return;
	    }
	    
	    if(sum + points[x][y] <= 0) {
	        points_ = points_ + abs(sum + points[x][y]) + 1;
	        sum = 1;
	    } else {
	        sum += points[x][y];
	    }
	    
	    recur(points, x, y+1, m, n, sum, points_);
	    recur(points, x+1, y, m, n, sum, points_);

	}
	
	int minPoints(int m, int n, vector<vector<int>> points) 
	{ 
	    // Your code goes here
	   // recur(points, 0, 0, m, n, 1, 1);
	   // return ans;
	   
	   vector<vector<int>> dp(m, vector<int>(n, 0));

        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (i == m - 1 && j == n - 1)
                    dp[i][j] = max(1, 1 - points[i][j]);
                else if (i == m - 1)
                    dp[i][j] = max(1, dp[i][j + 1] - points[i][j]);
                else if (j == n - 1)
                    dp[i][j] = max(1, dp[i + 1][j] - points[i][j]);
                else
                    dp[i][j] = max(1, min(dp[i + 1][j], dp[i][j + 1]) - points[i][j]);
            }
        }

        return dp[0][0];
	} 
};
