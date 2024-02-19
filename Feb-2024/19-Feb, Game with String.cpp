//User function Template for C++

class Solution{
public:
    int minValue(string s, int k){
        int res = 0;
        vector<int> count(26, 0);
        
        for(auto x: s) {
            count[x-'a']++;
        }
        
        priority_queue<int> pq;
        for(int x: count) {
            pq.push(x);
        }
        
        while(k--) {
            int x = pq.top(); pq.pop();
            pq.push(x-1);
        }
        
        while(!pq.empty()) {
            int x = pq.top(); pq.pop();
            res = res + x*x;
        }
        
        return res;
    }
};
