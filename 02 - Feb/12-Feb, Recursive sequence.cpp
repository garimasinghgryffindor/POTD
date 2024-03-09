
class Solution{
public:
    long long sequence(int n){
        // code here
        long long ans = 0;
        long long mod = 1e9 + 7;
        int num = 1;
        for(int i = 1; i <= n; i++) {
            long long temp = 1;
            for(int j = 0; j < i; j++) {
                temp = (temp*num)%mod;
                num++;
            }
            ans = (ans + temp)%mod;
        }
        return ans;
    }
};
