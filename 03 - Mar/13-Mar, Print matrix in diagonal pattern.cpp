/*You are required to complete this method */

class Solution{
  public:
    vector<int> matrixDiagonally(vector<vector<int>>&mat)
    {
         vector<int>res;
         bool flow = false;
         // false flow meaning => towards top-right
         // true flow meaning => towards bottom-left
         int i = 0, j = 0;
         int n = mat.size();
         int count = 0;
         
         while(count < 2*n - 1) {
             if(!flow) {
                 while(i >= 0 && j < n) {
                     res.push_back(mat[i][j]);
                     i--;
                     j++;
                 }
                 i++;
                 j--;
                 if(count < n-1) {
                     j++;
                 } else {
                     i++;
                 }
             } else {
                 while(i < n && j >= 0) {
                     res.push_back(mat[i][j]);
                     i++;
                     j--;
                 }
                 i--;
                 j++;
                 if(count < n-1) {
                     i++;
                 } else {
                     j++;
                 }
             }
             count++;
             flow = !flow;
         }
         
         return res;
    }
};
