// User function Template for C++

class Solution {
  public:
    int minRow(int n, int m, vector<vector<int>> a) {
        int res = -1;
        int c = INT_MAX;
        for(int i = 0; i < n; i++) {
            int count = 0;
            for(int j = 0; j < m; j++) {
                count += a[i][j];
            }
            if(count < c) {
                c = count;
                res = i+1;
            }
        }
        return res;
    }
};
