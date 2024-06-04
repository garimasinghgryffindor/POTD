class Solution {
  public:
    string binaryNextNumber(string s) {
        s.erase(0, s.find_first_not_of('0'));
        if (s.empty()) s = "0";
        int n = s.size();
        bool carry = true;
        for (int i = n - 1; i >= 0 && carry; --i) {
            if (s[i] == '0') {
                s[i] = '1';
                carry = false;
            } else {
                s[i] = '0';
            }
        }
        if (carry) {
            s = '1' + s;
        }
        return s;
    }
};0
