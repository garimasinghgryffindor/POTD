//User function Template for C++

class Solution{
    public:
    // function to convert a given Gray equivalent n to Binary equivalent.
    string bin(int n) {
        string res = "";
        while(n) {
            if(n%2 == 0) {
                res += "0";
            } else {
                res += "1";
            }
            n/=2;
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
    
    int binrev(string s) {
        int res = 0;
        for(int i = 0; i < s.length(); i++) {
            res += s[i]-'0';
            if(i != s.length()-1) res*=2;
        }
        return res;
    }
    
    int grayToBinary(int n)
    {
        if(n == 0 || n == 1) return n;
        
        string gray = bin(n);
        // cout<<"gray: "<<gray<<endl;
        string binary;
        if(gray[0] == '0') {
            binary = "0";
        } else {
            binary = "1";
        }
        // cout<<"binary_new: "<<binary<<endl;
        
        for(int i = 1; i < gray.size(); i++) {
            int x = binary[i-1]-'0';
            int y = gray[i]-'0';
            int res = x^y;
            binary += to_string(res);
        }
        
        // cout<<"binary: "<<binary<<endl;
        int res = binrev(binary);
        
        
        return res;
    }
};
