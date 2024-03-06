
class Solution{
    public:
    int DivisibleByEight(string s){
        int n = s.length();
        if(n <= 3) {
            int x = stoi(s);
            if(x%8 == 0) return 1;
            return -1;
        }
        
        string temp = s.substr(n-3, 3);
        int x = stoi(temp);
        if(x%8 == 0) return 1;
        return -1;
    }
};
