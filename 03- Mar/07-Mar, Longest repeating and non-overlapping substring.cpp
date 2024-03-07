class Solution {
    #define p 10000007
    vector<int> roll;

    bool rk(const string&s, int len, string&temp) {
        unordered_map<int, vector<int> > mp;
        int d = 31;
        int hash = 0;
        int first_occur = INT_MAX;
        bool found = false;
        
        for(int i = 0; i < len; i++) {
            hash = (hash*d + s[i]-'a')%p;
        }
        mp[hash].push_back(0);

        for(int i = len; i < s.length(); i++) {
            hash = ((hash - (s[i-len]-'a')*roll[len-1])%p + p )%p;
            hash = (hash * d)%p;
            hash = (hash + s[i]-'a')%p;
            
            if(mp.find(hash) != mp.end()) {
                // duplicate value found
                // let's recheck it for collision
                for(auto x: mp[hash]) {
                    string cur = s.substr(x, len);
                    string curr = s.substr(i-len+1, len);
                    if(cur.compare(curr)==0 && x+len-1 < i-len+1)
                    {
                        found = true;
                        if(x < first_occur) {
                            temp = curr;
                            first_occur = x;
                        }
                    }
                }
            }

            mp[hash].push_back(i-len+1);
        }

        return found;
    }
  public:
    string longestSubstring(string s, int n) {
        if(s.length() == 0) return "";
        
        roll.resize(n);
        roll[0] = 1;
        for (size_t i = 1; i < static_cast<size_t>(n); ++i)
            roll[i] = (31 * roll[i - 1]) % p;
        
        int l = 1, r = n;
        string ans = "";
        while(l <= r) {
            int mid = l + (r-l)/2;
            string temp = "";
            
            bool found = rk(s, mid, temp);
            
            if(found) {
                if(temp.size() > ans.size()) {
                    ans = temp;
                }
                l = mid+1;
            } else {
                r = mid-1;
            }
        }
        
        if(ans == "") return "-1";
        return ans;
    }
};
