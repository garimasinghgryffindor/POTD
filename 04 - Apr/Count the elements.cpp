// User function Template for C++
class Solution {
  public:
    vector<int> countElements(vector<int> &a, vector<int> &b, int n, vector<int> &query,
                              int q) {
        // Your code goes here;
        vector<int>res;
        sort(b.begin(), b.end());
        
        for(int idx: query) {
            int key = a[idx];
            int result = -1;
            // binary search
            int l = 0, r = b.size()-1;
            while(l <= r) {
                int mid = l + (r-l)/2;
                if(b[mid] <= key) {
                    l = mid+1;
                } else {
                    r = mid-1;
                    result = mid;
                }
            }
            if(result == -1) res.push_back(b.size());
            else res.push_back(result);
        }
        
        return res;
    }
};
