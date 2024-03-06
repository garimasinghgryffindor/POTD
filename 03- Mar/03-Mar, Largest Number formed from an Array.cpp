//User function template for C++
class Solution{
public:
	// The main function that returns the arrangement with the largest value as
	// string.
	// The function accepts a vector of strings
	static bool compare(string&a, string&b) {
	    string x = a+b;
	    string y = b+a;
	    return x > y;
	}
	
	string printLargest(int n, vector<string> &arr) {
	    string res = "";
	    sort(arr.begin(), arr.end(), compare);
	    for(int i = 0; i < n; i++) {
	        res = res + arr[i];
	    }
	    return res;
	}
};
