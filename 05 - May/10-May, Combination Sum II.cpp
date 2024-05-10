//User function Template for C++

class Solution{
public:
    void recur(vector<int>&arr, int idx, int n, int k, vector<vector<int>>&res, vector<int>&temp) {
        if(k == 0) {
            res.push_back(temp);
            return;
        }
        if(idx == n) return;
        
        for(int i = idx; i < n; i++) {
            if(i > idx && arr[i] == arr[i-1]) continue;
            if(arr[i] > k) break;
            temp.push_back(arr[i]);
            recur(arr, i+1, n, k-arr[i], res, temp);
            temp.pop_back();
        }
        
    }
    vector<vector<int>> CombinationSum2(vector<int> arr,int n,int k)
    {
        sort(arr.begin(), arr.end());
        vector<vector<int>>res;
        vector<int>temp;
        recur(arr, 0, n, k, res, temp);
        sort(res.begin(), res.end());
        return res;
    }
};
