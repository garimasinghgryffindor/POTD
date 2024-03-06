// Given a string str consisting of digits, you can divide it into sub-groups by separating the string into substrings. For example, 
// "112" can be divided as {"1", "1", "2"}, {"11", "2"}, {"1", "12"}, and {"112"}.

// A valid grouping can be done if you are able to divide sub-groups where the sum of digits in a sub-group is less than or equal to the 
// sum of the digits of the sub-group immediately right to it. Your task is to determine the total number of valid groupings that could be 
// done for a given string.

	
class Solution {
  public:
	// using pure recursion
	int recur(string str, int idx, int prevSum) {
	    if(idx == str.length()) return 1;
	    
	    int count = 0;
	    // where can we cut
	    for(int j = idx; j < str.length(); j++) {
	        int sum = 0;
	        for(int i = idx; i <= j; i++) {
	            sum += str[i] - '0';
	        }
	        if(sum >= prevSum) {
	            count += recur(str, j+1, sum);
	        }
	    }
	    
	    return count;
	}
	
	int TotalCount(string str){
	    // Code here
	    int idx = 0, prevSum = 0;
	    return recur(str, idx, prevSum);
	}
};


class Solution{
	public:
	// using memoization
	int recur(string str, int idx, int prevSum, vector<vector<int>>&mem) {
	    if(idx == str.length()) return 1;
	    
	    if(mem[idx][prevSum] != -1) return mem[idx][prevSum];
	    
	    int count = 0;
	    // where can we cut
	    for(int j = idx; j < str.length(); j++) {
	        int sum = 0;
	        for(int i = idx; i <= j; i++) {
	            sum += str[i] - '0';
	        }
	        if(sum >= prevSum) {
	            count += recur(str, j+1, sum, mem);
	        }
	    }
	    
	    return (mem[idx][prevSum] = count);
	}
	
	int TotalCount(string str){
	    // Code here
	    int n = str.length();
	    vector<vector<int>> mem(n+1, vector<int>(9*n+1, -1));
	    int idx = 0, prevSum = 0;
	    return recur(str, idx, prevSum, mem);
	}

};



class Solution{
	public:
	int TotalCount(string str){
	    // using tabulation
	    int n = str.length();
	    vector<vector<int>> dp(n+1, vector<int>(9*n+1, 0));
	   // int idx = 0, prevSum = 0;
	    for(int i = 0; i < 9*n+1; i++) {
	        dp[n][i] = 1;
	    }
	    
	    for(int idx = n-1; idx >= 0; idx--) {
	        for(int prevSum = 9*idx; prevSum >= 0; prevSum--) {
	            int count = 0;
        	    // where can we cut
        	    int sum = 0;
        	    for(int j = idx; j < str.length(); j++) {
        	        
        	       // for(int i = idx; i <= j; i++) {
        	            sum += str[j] - '0';
        	       // }
        	        if(sum >= prevSum) {
        	            count += dp[j+1][sum];
        	        }
        	    }
        	    
        	    dp[idx][prevSum] = count;
	        }
	    }
	    
	    return dp[0][0];
	}

};
