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

