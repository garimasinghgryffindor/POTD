class Solution{
public:
    vector<int> recamanSequence(int n){
        // code here
        unordered_map<int, bool>mp;
        vector<int>res(n, 0);
        mp[0] = true;
        
        for(int i = 1; i < n; i++) {
            int x = res[i-1] - i;
            if(x > 0 && mp.find(x) == mp.end()) {
                res[i] = x;
                mp[x] = true;
            } else {
                res[i] = res[i-1] + i;
                mp[res[i-1]+i] = true;
            }
        }
        
        return res;
    }
};
