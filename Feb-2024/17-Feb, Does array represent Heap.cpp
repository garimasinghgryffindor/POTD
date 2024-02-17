class Solution{
    public:
    bool isMaxHeap(int arr[], int n)
    {
        // Your code goes here
        for(int i = n/2; i >= 0; i--) {
            int c1 = 2*i+1, c2 = 2*i+2;
            if(c1 < n && arr[i] < arr[c1]) {
                return false;
            } else if(c2 < n && arr[i] < arr[c2]) {
                return false;
            }
        }
        return true;
    }
};
