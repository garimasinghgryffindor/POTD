class Solution{
	public:
	    vector<string>res;
	    
	    void recur(string&s, int idx, string curr) {
	        if(idx == s.length()) {
	            if(curr.length()) {
	                res.push_back(curr);
	            }
	            return;
	        }
	        
	        // not take
	        recur(s, idx+1, curr);
	        // take
	        curr = curr + s[idx];
	        recur(s, idx+1, curr);
	    }
	    
		vector<string> AllPossibleStrings(string s){
		    recur(s, 0, "");
		    sort(res.begin(), res.end());
		    return res;
		}
};
