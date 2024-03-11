//User function template for C++
class Solution{
public:	
    
    bool binarySearch(vector<vector<int>> &mat, int key) {
        int l = 0, r = mat.size()*mat[0].size()-1;
        
        while(l <= r) {
            int mid = l + (r-l)/2;
            int i = mid/mat[0].size();
            int j = mid%mat[0].size();
            
            if(mat[i][j] == key) return true;
            if(mat[i][j] < key) l = mid+1;
            else r = mid-1;
        }
        
        return false;
    }
	
	int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int n, int x)
	{
	    // Your code goes here
	    int count = 0;
	    for(int i = 0; i < mat1.size(); i++) {
	        for(int j = 0; j < mat1[0].size(); j++) {
	            int num = mat1[i][j];
	            if(binarySearch(mat2, x-num)) {
	                count++;
	            }
	        }
	    }
	    
	    return count;
	}
};
