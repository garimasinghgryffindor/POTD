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


// MEMOIZATION
class Solution
{
    int mem[21][21][21];
    public:
        int recur(string a, string b, string c, int x, int y, int z) {
            if(x == 0 || y == 0 || z == 0) return 0;
            
            if(mem[x][y][z] != -1) return mem[x][y][z];
            
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
                
                return mem[x][y][z] = max({temp1,temp2,temp3,temp4,temp5,temp6});
            }
        }
        
        int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
        {
            // using recursion
            memset(mem, -1, sizeof(mem));
            return recur(A, B, C, n1, n2, n3);
        }
};


// TABULATION
class Solution
{
    int mem[21][21][21];
    public:
        int LCSof3 (string a, string b, string c, int n1, int n2, int n3)
        {
            // using tabulation
            memset(mem, -1, sizeof(mem));
            
            for(int i = 0; i < 21; i++) {
                for(int j = 0; j < 21; j++) {
                    mem[0][i][j] = 0;
                    mem[i][0][j] = 0;
                    mem[i][j][0] = 0;
                }
            }
            
            for(int i = 1; i <= n1; i++) {
                for(int j = 1; j <= n2; j++) {
                    for(int k = 1; k <= n3; k++) {
                        if(a[i-1] == b[j-1] && b[j-1] == c[k-1]) {
                             mem[i][j][k] = 1 + mem[i-1][j-1][k-1];
                        } else {
                            int temp1 = 0;
                            if(a[i-1] == b[j-1]) {
                                temp1 = mem[i][j][k-1];
                            }
                            int temp2 = 0;
                            if(a[i-1] == c[k-1]) {
                                temp2 = mem[i][j-1][k];
                            }
                            int temp3 = 0;
                            if(b[j-1] == c[k-1]) {
                                temp3 = mem[i-1][j][k];
                            }
                            
                            int temp4 = mem[i-1][j-1][k];
                            int temp5 = mem[i][j-1][k-1];
                            int temp6 = mem[i-1][j][k-1];
                            
                            mem[i][j][k] = max({temp1,temp2,temp3,temp4,temp5,temp6});
                        }
                    }
                }
            }
            
            return mem[n1][n2][n3];
        }
};
