class Solution {
  public:
    /*You are requried to complete this method */
    long long max_Books(int arr[], int n, int k) {
        long long res = 0;
        long long curr = 0;
       
        for(int i = 0; i < n; i++) {
            if(arr[i] <= k) {
                curr+=arr[i];
            } else {
                res = max(res, curr);
                curr = 0;
            }
        }
        
        res = max(res, curr);
        
        return res;
    }
};
