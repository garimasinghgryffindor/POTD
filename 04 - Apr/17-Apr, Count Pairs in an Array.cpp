

class Solution{
    public:
    int countPairs(int arr[] , int n ) 
    {
        // Your code goes here
        int res = 0;
        vector<int>v(n, 0);
        for(int i = 0; i < n; i++) {
            v[i] = arr[i]*i;
        }
        vector<int>temp = v;
        sort(temp.begin(), temp.end());
        
        for(int i = n-1; i >= 0; i--) {
            auto ub = upper_bound(temp.begin(), temp.end(), v[i]);
            auto lb = lower_bound(temp.begin(), temp.end(), v[i]);
            int x = ub - temp.begin();
            int y = lb - temp.begin();
            
            res += temp.size()-x;
            temp.erase(temp.begin()+y);
        }
        
        return res;
    }
};
