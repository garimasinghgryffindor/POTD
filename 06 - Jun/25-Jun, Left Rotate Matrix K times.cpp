// User function Template for C++

class Solution {
  public:
    vector<vector<int>> rotateMatrix(int k, vector<vector<int>> mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>>res(n, vector<int>(m));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                res[i][j] = mat[i][(j+k)%m];
            }
        }
        
        return res;
    }
};
