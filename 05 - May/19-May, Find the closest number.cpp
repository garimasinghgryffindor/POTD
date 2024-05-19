class Solution{
    public:
    int findClosest( int n, int k,int arr[]) 
    { 
        int left = 0, right = n - 1;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            if (arr[mid] < k) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        if (left > 0 && abs(arr[left - 1] - k) < abs(arr[left] - k)) {
            return arr[left - 1];
        } else {
            return arr[left];
        }
    } 
};
