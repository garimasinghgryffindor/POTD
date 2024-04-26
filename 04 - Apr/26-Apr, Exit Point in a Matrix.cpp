class Solution {
  public:
    vector<int> FindExitPoint(int n, int m, vector<vector<int>>& matrix) {
        
        int i = 0, j = 0;
        int dir = 0;
        // 0-> left-right
        // 1-> right-left
        // 2-> top-bottom
        // 3-> bottom-top
        
        while(i < n && j < m && i >= 0 && j >= 0) {
            if(matrix[i][j]) {
                switch(dir) {
                    case 0: dir = 2;    break;
                    case 1: dir = 3;    break;
                    case 2: dir = 1;    break;
                    case 3: dir = 0;    break;
                    default: dir = -1;
                }
                matrix[i][j] = 0;
            } else {
                switch(dir) {
                    case 0: j++;    break;
                    case 1: j--;    break;
                    case 2: i++;    break;
                    case 3: i--;    break;
                }
            }
        }
        
        i = min(i, n-1);
        j = min(j, m-1);
        i = max(i, 0);
        j = max(j, 0);
        
        return {i, j};
    }
    
    
};
