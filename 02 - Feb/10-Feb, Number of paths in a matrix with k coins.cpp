class Solution {
public:
    void recur(vector<vector<int>>&arr,int r,int c,int k,long long&res) {
        // if(k == 0 && ((r < 0 && c == 0) || (c < 0 && r == 0))) {
        //     res++;  return;
        // }
        if(r < 0 || c < 0) return;
        
        if(k < 0) return;
        
        if(k-arr[r][c] == 0) {
            if(r == 0 && c == 0) res++;
        }
        recur(arr, r-1, c, k-arr[r][c], res);
        recur(arr, r, c-1, k-arr[r][c], res);
    }
    
    long long numberOfPath(int n, int k, vector<vector<int>> &arr){
        long long res = 0;
        recur(arr, n-1, n-1, k, res);
        return res;
    }
};
