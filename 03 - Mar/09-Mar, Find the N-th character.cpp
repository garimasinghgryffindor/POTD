//User function template for C++

class Solution{
  public:
    char nthCharacter(string s, int r, int n) {
        //code here
        // 1100 => after 6 iterations the first 1 will be => 101010101010
        // if '1' => if place is even => then 1 otherwise 0
        // if '0' => if place is odd => then 0 otherwise 1
        int len = s.length();
        
        for(int i = 0; i < r; i++) {
            string temp = s;
            for(int j = 0; j < len; j++) {
                if(temp[j/2] == '0') {
                    if(j%2 == 0) {
                        // i.e; even
                        s[j] = '0';
                    } else {
                        s[j] = '1';
                    }
                } else {
                    if(j%2 == 0) {
                        // i.e; even
                        s[j] = '1';
                    } else {
                        s[j] = '0';
                    }
                }
            }
        }
        
        return s[n];
    }
};
