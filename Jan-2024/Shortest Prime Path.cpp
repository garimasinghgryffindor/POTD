//User function Template for C++
class Solution{   
public:
    bool isPrime(int n) {
        for(int i=2;i*i<=n;i++){
            if(n%i==0)  return 0;
        }
        return 1;
    }
    
    int solve(int Num1,int Num2)
    {   
      //code here
      int x = Num1;
      unordered_map<string, int> st;
      string start = to_string(x);
      
      queue<string> q;
      q.push(start);
      
      int level = 0;
      while(!q.empty()) {
          int sz = q.size();
          for(int i = 0; i < sz; i++) {
               string temp = q.front();     q.pop();
               if(temp == to_string(Num2)) return level;
               for(int pos = 0; pos < 4; pos++) {
                   for(int digit = 0; digit <= 9; digit++) {
                       string newString = temp;
                    //   cout<<newString<<"   ";
                       newString[pos] = digit + '0';
                       if(stoi(newString) >= 1000 && !st[newString] && isPrime(stoi(newString)) ) {
                           q.push(newString);
                           st[newString]++;
                       }
                   }
               }
          }
          
          level++;
      }
      
    //   return level;
    }
};
