//User function template for C++
class Solution{
public:
	string removeDuplicates(string str) {
	    unordered_map<char, bool> mp;
	    string ans = "";
	    for(auto x: str) {
	        if(mp.find(x) == mp.end()) {
	            ans = ans + x;
	            mp[x] = true;
	        }
	    }
	    
	    return ans;
	}
};
