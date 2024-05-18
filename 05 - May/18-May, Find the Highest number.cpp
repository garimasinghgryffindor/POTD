class Solution {
public:
    int findPeakElement(vector<int>& a) 
    {
        int n = a.size();
        int l = 0, r = n-1;
        
        int mid = 0;
        while(l < r) {
            mid = l + (r-l)/2;
            if(mid > 0 && a[mid] > a[mid-1] && mid < n-1 && a[mid] > a[mid+1]) return a[mid];
            else if(mid == 0) {
                return max(a[0], a[1]);
            } else if(mid == n-1) {
                return max(a[n-1], a[n-2]);
            } else {
                if(a[mid] < a[mid-1]) {
                    r = mid-1;
                } else {
                    l = mid+1;
                }
            }
        }
        
        return a[l];
    }
};
