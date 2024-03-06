//User function template for C++

class Solution
{
  public:
    //Function to check if a string is Pangram or not.
    bool checkPangram (string s) {
        set<char> st;
        for(char x: s) {
            if(x >= 'a' && x <= 'z') st.insert(x);
            else if(x >= 'A' && x <= 'Z') st.insert(x+32);
            
            if(st.size() == 26) return true;
        }
        
        return false;
    }

};
