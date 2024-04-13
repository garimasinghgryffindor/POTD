class Solution {
  public:
    string to_binary(long long n) {
        string res = "";
        while(n) {
            if(n%2 != 0) {
                res = "1" + res;
            } else {
                res = "0" + res;
            }
            n/=2;
        }
        return res;
    }
    
    long long to_num(string s) {
        long long res = 0;
        for(int i = 0; i < 32; i++) {
            // cout<<res<<".    ";
            if(s[i] == '0') {
                res = res*2;
            } else {
                res = res*2 + 1;
            }
        }
        return res;
    }
    
    long long reversedBits(long long x) {
        string str = to_binary(x);
        
        int n_rem = 32-str.length();
        // cout<<n_rem<<endl;
        
        string zeros = "";
        for(int i = 0; i < n_rem; i++) {
            zeros += "0";
        }
        str = zeros + str;
        // cout<<str<<endl;
        // cout<<str.length()<<endl;
        reverse(str.begin(), str.end());
        
        
        long long res = to_num(str);
        
        return res;
    }  
};



