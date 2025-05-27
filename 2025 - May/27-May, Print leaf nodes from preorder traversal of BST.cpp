class Solution {
  public:
    vector<int> leafNodes(vector<int>& preorder) {
        // code here
        vector<int>res;
        stack<int>st;
        for(auto x: preorder) {
            if(st.empty()) {
                st.push(x);
            } else {
                int last_popped = -1;
                int cnt = 0;
                if(x < st.top()) {
                    // stack's top is definitely not a leaf node
                    st.push(x);
                } else {
                    // otherwise
                    // it could be stack's top right child or it's parent's right child
                    int tp = st.top();
                    st.pop();
                    if(st.empty()) {
                        // definitely my right child
                        // in that case I am not a leaf node
                        st.push(x);
                    } else {
                        if(st.top() > x) {
                            // I have to be the right child of the last_popped element
                            // in that case I am not a leaf node
                            st.push(x);
                        } else {
                            // otherwise
                            // I am a leaf node
                            res.push_back(tp);
                            while(st.size() && st.top() < x) {
                                st.pop();
                            }
                            st.push(x);
                        }
                    }
                }
            }
        }
        res.push_back(st.top());
        
        return res;
    }
};
