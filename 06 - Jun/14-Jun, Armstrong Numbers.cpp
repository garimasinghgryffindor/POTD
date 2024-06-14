// User function Template for C++
class Solution {
  public:
    string armstrongNumber(int n) {
        int ans = 0;
        int x = n;
        while(n) {
            ans += pow((n%10), 3);
            n/=10;
        }
        if(ans == x) return "true";
        return "false";
    }
};
