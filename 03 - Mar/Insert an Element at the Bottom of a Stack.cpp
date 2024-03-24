//User function Template for C++

class Solution{
public:
    stack<int> insertAtBottom(stack<int> st,int x){
        stack<int>temp;
        while(!st.empty()) {
            int tp = st.top();  st.pop();
            temp.push(tp);
        }
        st.push(x);
        while(!temp.empty()) {
            int tp = temp.top();    temp.pop();
            st.push(tp);
        }
        
        return st;
    }
};
