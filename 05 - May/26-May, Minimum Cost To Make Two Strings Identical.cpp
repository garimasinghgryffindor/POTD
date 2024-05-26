class Solution {

  public:
  vector<vector<int>>dp;
    int recur(string&x, string&y, int&costx, int&costy, int idx1, int idx2) {
        if(idx1 == x.length()) {
            int temp = y.length()-idx2;
            temp = temp*costy;
            return temp;
        }
        
        if(idx2 == y.length()) {
            int temp = x.length()-idx1;
            temp = temp*costx;
            return temp;
        }
        
        if(dp[idx1][idx2] != -1) return dp[idx1][idx2];
        
        if(x[idx1] == y[idx2]) {
            return recur(x,y,costx,costy,idx1+1,idx2+1);
        }
        int temp1 = costx+recur(x,y,costx,costy,idx1+1,idx2);
        int temp2 = costy+recur(x,y,costx,costy,idx1,idx2+1);
        
        return dp[idx1][idx2] = min(temp1, temp2);
    }
    
    int findMinCost(string x, string y, int costX, int costY) {
        int res = 0;
        dp.resize(x.length(), vector<int>(y.length(), -1));
        res = recur(x,y,costX,costY,0,0);
        return res;
    }
};
