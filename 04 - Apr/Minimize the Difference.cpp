
class Solution {
  public:
    int minimizeDifference(int n, int k, vector<int> &arr) {
        // code here
        vector<int>prefMin(n, INT_MAX), prefMax(n, INT_MIN);
        vector<int>suffMin(n, INT_MAX), suffMax(n, INT_MIN);
        
        prefMin[0] = arr[0];
        prefMax[0] = arr[0];
        suffMin[n-1] = arr[n-1];
        suffMax[n-1] = arr[n-1];
        
        for(int i = 1; i < n; i++) {
            prefMin[i] = min(prefMin[i-1], arr[i]);
            prefMax[i] = max(prefMax[i-1], arr[i]);
            suffMin[n-i-1] = min(suffMin[n-i], arr[n-i-1]);
            suffMax[n-i-1] = max(suffMax[n-i], arr[n-i-1]);
        }
        
        int res = INT_MAX;
        
        int l = 0, r = k-1;
        
        while(r < n) {
            int leftHalf_l = min(0, l-1);
            int leftHalf_r = l-1;
            int rightHalf_l = r+1;
            int rightHalf_r = max(r+1, n-1);
            int mn = INT_MAX;
            int mx = INT_MIN;
            
            // creating the left half
            if(leftHalf_l < 0) {
                // leave it
            } else {
                // do something
                mn = min(mn, prefMin[leftHalf_r]);
                mx = max(mx, prefMax[leftHalf_r]);
            }
            
            // creating the right half
            if(rightHalf_r > n-1) {
                // leave it
            } else {
                // do something
                mn = min(mn, suffMin[rightHalf_l]);
                mx = max(mx, suffMax[rightHalf_l]);
            }
            
            res = min(res, mx-mn);
            r++;
            l++;
        }
        
        
        return res;
    }
};
