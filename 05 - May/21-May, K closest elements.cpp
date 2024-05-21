// User function template for C++

class Solution {
  public:
    vector<int> printKClosest(vector<int> arr, int n, int k, int x) {
        vector<int>res;
        int left = 0, right = n-1;
        while(left < right) {
            int mid = left + (right-left)/2;
            if(arr[mid] < x) {
                left = mid+1;
            } else {
                right = mid;
            }
        }
        
        int mn;
        if (left > 0 && abs(arr[left - 1] - x) < abs(arr[left] - x)) {
            mn = left - 1;
        } else {
            mn = left;
        }
        
        if(arr[mn] != x) {
            res.push_back(arr[mn]);     k--;
        }
    
        int l = mn-1, r = mn+1;
        
        while(k--) {
            if(l >= 0 && r < n) {
                if(abs(arr[l]-x) < abs(arr[r]-x)) {
                    res.push_back(arr[l--]);
                } else {
                    res.push_back(arr[r++]);
                }
            } else if(l >= 0) {
                res.push_back(arr[l--]);
            } else {
                res.push_back(arr[r++]);
            }
        }
        
        return res;
    }
};
