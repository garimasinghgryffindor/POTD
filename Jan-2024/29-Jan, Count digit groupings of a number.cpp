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

