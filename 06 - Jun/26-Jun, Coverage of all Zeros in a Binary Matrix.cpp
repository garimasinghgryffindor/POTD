

class Solution {
  public:
    int findCoverage(vector<vector<int>>& matrix) {
        int sum = 0;
        int r = matrix.size();
        int c = matrix[0].size();
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(matrix[i][j] == 1) {
                    if(i > 0 && matrix[i-1][j] == 0) {
                        sum++;
                    }
                    if(j > 0 && matrix[i][j-1] == 0) {
                        sum++;
                    }
                    if(i < r-1 && matrix[i+1][j] == 0) {
                        sum++;
                    }
                    if(j < c-1 && matrix[i][j+1] == 0) {
                        sum++;
                    }
                }
            }
        }
        
        return sum;
    }
};
