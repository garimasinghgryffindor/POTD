// Given an array p[] of length n used to denote the dimensions of a series of matrices such that dimension of i'th matrix is p[i] * p[i+1]. There are a total of n-1 matrices. Find the most efficient way to multiply these matrices together. 
// The problem is not actually to perform the multiplications, but merely to decide in which order to perform the multiplications such that you need to perform minimum number of multiplications. There are many options to multiply a chain of matrices because matrix multiplication is associative i.e. no matter how one parenthesize the product, the result will be the same. Please see examples for more clarifications.

// NOTE : As there can be multiple possible answers, the console would print "True" for correct string and "False" for incorrect string. You need to only return a string which performs minimum number of multiplications.

  
class Solution{
public:
    string matrixChainOrder(int p[], int n){
        // code here
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        vector<vector<string>> ans(n, vector<string>(n, ""));
        // actual matrix representation => idx 1,2,3. ....
        // so total matrices there are: n-1
        
        for(int i = 0; i < n; i++) {dp[i][i] = 0;}
        
        for(int i = 1; i < n; i++) {
            char x = 'A' + i-1;
            ans[i][i] = ans[i][i] + x;
        }
        
        for(int len = 2; len <= n-1; len++) {
            for(int start = 1; start <= n-len; start++) {
                int end = start + len - 1;
                for(int breakpoint = start; breakpoint < end; breakpoint++) {
                    int temp = dp[start][breakpoint] + dp[breakpoint+1][end] + p[start-1]*p[breakpoint]*p[end];
                    
                    if(temp < dp[start][end]) {
                        dp[start][end] = temp;
                        char x = 'A'+start-1;
                        ans[start][end] = "("+ans[start][breakpoint]+ans[breakpoint+1][end]+")";
                    }
                }
            }
        }
        
        // cout<<ans[1][n-1];
        return ans[1][n-1];
    }
};


