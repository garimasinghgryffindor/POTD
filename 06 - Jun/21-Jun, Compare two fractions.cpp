
class Solution {
  public:
    string compareFrac(string str) {
        int a=0,b=0,c=0,d=0;
        int x = 1;
        bool flag = false;
        for(auto ch: str) {
            if(ch >= '0' && ch <= '9') {
                flag = true;
                switch(x) {
                    case 1: a=a*10+(ch-'0');    break;
                    case 2: b=b*10+(ch-'0');    break;
                    case 3: c=c*10+(ch-'0');    break;
                    case 4: d=d*10+(ch-'0');    break;
                }
            } else {
                if(flag) x++;
                flag = false;
            }
        }
        
        if((float)a/b == (float)c/d) return "equal";
        else if((float)a/b > (float)c/d) return to_string(a)+"/"+to_string(b);
        else return to_string(c)+"/"+to_string(d);
    }
};
