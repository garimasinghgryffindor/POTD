class Solution
{
    public:
        int recur(string a, string b, string c, int x, int y, int z) {
            if(x == 0 || y == 0 || z == 0) return 0;
            
            if(a[x-1] == b[y-1] && b[y-1] == c[z-1]) {
                return 1 + recur(a,b,c,x-1,y-1,z-1);
            } else {
                int temp1 = 0;
                if(a[x-1] == b[y-1]) {
                    temp1 = recur(a,b,c,x,y,z-1);
                }
                int temp2 = 0;
                if(a[x-1] == c[z-1]) {
                    temp2 = recur(a,b,c,x,y-1,z);
                }
                int temp3 = 0;
                if(b[y-1] == c[z-1]) {
                    temp3 = recur(a,b,c,x-1,y,z);
                }
                
                int temp4 = recur(a,b,c,x-1,y-1,z);
                int temp5 = recur(a,b,c,x,y-1,z-1);
                int temp6 = recur(a,b,c,x-1,y,z-1);
                
                return max({temp1,temp2,temp3,temp4,temp5,temp6});
            }
        }
        
        int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
        {
            // using recursion
            return recur(A, B, C, n1, n2, n3);
        }
};
