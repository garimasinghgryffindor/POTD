class Solution{
    public:
        
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int a[], int n) 
    {
        // using extra space
        vector<int>rightMax(n);
        rightMax[n-1] = a[n-1];
        for(int i = n-2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i+1], a[i]);
        }
        
        int i = 0, j = 0;
        int res = INT_MIN;
        while(i < n && j < n) {
            if(a[i] <= rightMax[j]) {
                res = max(res, j-i);
                j++;
            } else {
                i++;
            }
        }
        
        return res;
    }
};
