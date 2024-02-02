//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string s) {
        //Your code here
        int res = 0;
        bool sign = 1;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '-' && i == 0) { sign = false; continue; }
            if(s[i] >= '0' && s[i]<= '9') {
                res = res*10 + (s[i] - '0');
            } else return -1;
        }
        
        if(!sign) return -1*res;
        
        return res;
    }
};
