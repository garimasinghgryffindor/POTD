class Solution {
  public:
    int swapNibbles(int n) {
        string ans = "";
        
        int i = 0;    
        while(i < 8) {
            if(n%2 == 0) {
                ans = "0" + ans;
            } else {
                ans = "1" + ans;
            }
            n /= 2;
            i++;
        }
        
        // cout<<"ans:  "<<ans<<endl;
        
        string x = ans.substr(0, 4);
        string y = ans.substr(4, 4);
        y = y+x;
        // cout<<"y: "<<y<<endl;
        i = 0;
        int res = 0;
        while(i < 8) {
            if(y[i]-'0' == 1) {
                res = res+1;
            } else {
                
            }
            res*=2;
            i++;
        }
        
        res/=2;
        
        return res;
    }
};
