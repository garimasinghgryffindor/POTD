
class Solution {
  public:
    long long maxTip(int n, int x, int y, vector<int> &arr, vector<int> &brr) {
        long long res = 0;
        vector<pair<int, int>> vec(n);
        for(int i = 0; i < n; i++) {
            vec[i] = {abs(arr[i]-brr[i]), i};
        }
        sort(vec.rbegin(), vec.rend());
        for(auto ptr: vec) {
            int idx = ptr.second;
            if(y == 0 || (x > 0 && arr[idx] > brr[idx])) {
                res += arr[idx];
                x--;
            } else {
                res += brr[idx];
                y--;
            }
        }
        
        return res;
    }
};
