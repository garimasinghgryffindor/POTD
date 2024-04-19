class Solution{
    public:
    //arr1,arr2 : the arrays
    // n, m: size of arrays
    //Function to return a list containing the union of the two arrays. 
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        vector<int> res;
        int l1 = 0, l2 = 0;
        
        while(l1 < n && l2 < m) {
            if(arr1[l1] < arr2[l2]) {
                res.push_back(arr1[l1]);
                while(l1+1 < n && arr1[l1] == arr1[l1+1]) l1++;
                l1++;
            } else if(arr2[l2] < arr1[l1]) {
                res.push_back(arr2[l2]);
                while(l2+1 < m && arr2[l2] == arr2[l2+1]) l2++;
                l2++;
            } else {
                res.push_back(arr1[l1]);
                while(l1+1 < n && arr1[l1] == arr1[l1+1]) l1++;
                l1++;
                while(l2+1 < m && arr2[l2] == arr2[l2+1]) l2++;
                l2++;
            }
        }
        
        while(l1 < n) {
            res.push_back(arr1[l1]);
            while(l1+1 < n && arr1[l1] == arr1[l1+1]) l1++;
            l1++;
        }
        while(l2 < m) {
            res.push_back(arr2[l2]);
            while(l2+1 < m && arr2[l2] == arr2[l2+1]) l2++;
            l2++;
        }
        
        return res;
    }
};
