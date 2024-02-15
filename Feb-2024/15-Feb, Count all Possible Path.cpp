class Solution {
public:
	int isPossible(vector<vector<int>>paths){
	    // Code here
	    for(auto i: paths) {
	        if(accumulate(i.begin(), i.end(), 0)%2 != 0) return false;
	    }
	    return true;
	}
};
