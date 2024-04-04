class Solution
{
    public:
    //Function to find sum of all possible substrings of the given string.
    int mod = 1e9+7;
    long long sumSubstrings(string s){
        long long res = 0;
        long long prev = 0;
        long long curr = 0;
        int n = s.length();
        for(int i = 0; i < n; i++) {
            curr = ((prev*10)%mod + (s[i]-'0')*(i+1)%mod)%mod;
            res = (res + curr)%mod;
            prev = curr;
        }
        
        return res;
    }
};
