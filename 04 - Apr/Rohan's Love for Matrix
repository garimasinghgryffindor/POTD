// User function Template for C++
class Solution {
  public:
    int MOD = 1e9+7;
    int firstElement(int n) {
        // code here
        int x = 1, y = 0;
        for(int i = 1; i < n; i++) {
            int temp = (x+y)%MOD;
            y = x;
            x = temp;
        }
        
        return x;
    }
};
