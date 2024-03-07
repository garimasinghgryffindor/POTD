//User function template for C++
class Solution{
public:	
	bool sameFreq(string s)
	{
	    // code here
	    vector<int>count(26, 0);
	    for(auto x: s) {
	        count[x-'a']++;
	    }
	    
	    int freq = 0;
	    int mx_index = -1;
	    
	    for(int i = 0; i < 26; i++) {
	        if(count[i] > 0) {
	            if(count[i] > freq) {
	                freq = count[i];
	                mx_index = i;
	            }
	        }
	    }
	    
	    // either all of those others are equal to freq
	    // or all of those others are freq-1
	    
	    bool flag = true;
	    for(int i = 0; i < 26; i++) {
	        if(count[i] == 0) continue;
	        if(count[i] != freq) {
	            flag = false;
	            break;
	        }
	    }
	    
	    if(flag) return true;
	   
	    for(int i = 0; i < 26; i++) {
	        if(count[i] == 0) continue;
	        if(i == mx_index) continue;
	        if(count[i] != freq-1) return false;
	    }
	    
	    
	    return true;
	}
};
