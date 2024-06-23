// User function template for C++
class Solution {
  public:

    vector<int> bracketNumbers(string str) {
        int op = 0;
        vector<int> v;
        vector<int> st;
        
        for (auto& c : str) {
            if (c == '(') {
                op++;
                st.push_back(op);
                v.push_back(op);
            } else if (c == ')') {
                v.push_back(st.back());
                st.pop_back();
            }
        }
        return v;
    }
};
