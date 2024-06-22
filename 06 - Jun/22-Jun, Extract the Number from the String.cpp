// User function Template for C++

class Solution {
  public:
    long long ExtractNumber(string sentence) {
        long long res = -1;
        long long temp = 0;
        bool flag = false;
        bool isNine = false;
        
        for(auto x: sentence) {
            if(x >= '0' && x <= '9') {
                if(x == '9') {
                    isNine = true;
                }
                temp = temp * 10 + (x - '0');
                flag = true;
            } else {
                if(flag && (!isNine)) {
                    res = max(res, temp);
                }
                temp = 0;
                flag = false;
                isNine = false;  // Move this line here to reset isNine when a non-digit character is encountered
            }
        }
    
        if(flag && (!isNine)) {
            res = max(res, temp);
        }
        
        return res;
    }
};
