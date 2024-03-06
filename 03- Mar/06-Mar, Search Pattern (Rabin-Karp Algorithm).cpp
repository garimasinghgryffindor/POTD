class Solution
{
    #define ll long long
    public:
        vector<int> search(string pattern, string text)
        {
            vector<int> res;
            int d = 31;
            ll hash = 0;
            ll curr = 0;
            int n = text.length(), p = pattern.length();
            
            for(int i = 0; i < p; i++) {
                hash = hash * d + pattern[i] - 'a';
                curr = curr * d + text[i] - 'a';
            }
            
            ll maxPow = 1;
            for (int i = 0; i < p - 1; i++) {
                maxPow = (maxPow * d);
            }

            if (hash == curr) {
                bool flag = true;
                for (int i = 0; i < p; i++) {
                    if (pattern[i] != text[i]) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    res.push_back(1);
                }
            }

            for (int i = p; i < n; i++) {
                curr = (curr - (text[i - p] - 'a') * maxPow) * d + (text[i] - 'a');

                if (hash == curr) {
                    bool flag = true;
                    for (int j = 0; j < p; j++) {
                        if (pattern[j] != text[i - p + 1 + j]) {
                            flag = false;
                            break;
                        }
                    }
                    if (flag) {
                        res.push_back(i - p + 2);
                    }
                }
            }

            return res;
        }
};
