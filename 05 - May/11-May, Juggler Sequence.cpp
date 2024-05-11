// User function Template for C++

class Solution {
  public:
    vector<long long> jugglerSequence(long long n) {
        // code here
        vector<long long> res;
        while(n != 1) {
            res.push_back(n);
            if(n%2 == 0) {
                n = sqrt(n);
            } else {
                n = n*sqrt(n);
            }
        }
        res.push_back(1);
        
        return res;
    }
};
