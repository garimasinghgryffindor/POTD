// User function Template for C++
//  Class Solution to contain the method for solving the problem.
class Solution {
  public:
    // Function to determine if array arr can be split into three equal sum sets.
    vector<int> findSplit(vector<int>& arr) {
        int n = arr.size();
        vector<long long>pref(n, 0);
        long long sum = 0;
        pref[0] = arr[0];
        for(int i = 1; i < n; i++) {
            pref[i] = pref[i-1] + arr[i];
        }
        sum = pref[n-1];
        
        if(sum%3 != 0) return {-1, -1};
        
        long long idealSum = sum/3;
        int left = -1, right = -1;
        for(int i = 0; i < n; i++) {
            if(left == -1) {
                if(pref[i] == idealSum) {
                    left = i;
                }
            } else {
                if(pref[i] == 2*idealSum) {
                    right = i;
                }
            }
        }
        
        if(left != -1 && right != -1) return {left, right};
    
        return {-1, -1};
    }
};
