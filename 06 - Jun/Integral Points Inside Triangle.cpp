// User function Template for C++

class Solution {
  public:
    
    long long gcd(long long x, long long y) {
        while(y != 0) {
            long long temp = y;
            y = x%y;
            x = temp;
        }
        
        return x;
    }
  
    long long boundaryPoints(long long x1, long long y1, long long x2, long long y2) {
        return gcd(abs(x2-x1) , abs(y2-y1)) + 1;
    }
    
    long long int InternalCount(long long int p[], long long int q[],
                                long long int r[]) {
        long long A = abs(p[0]*(q[1] - r[1]) + q[0]*(r[1] - p[1]) + r[0]*(p[1] - q[1]));
        
        long long B = boundaryPoints(p[0], p[1], q[0], q[1]) + boundaryPoints(p[0], p[1], r[0], r[1]) + boundaryPoints(q[0], q[1], r[0], r[1]) - 3;
        
        // Using Pick's Theorem, the number of internal lattice points 
        // I in a simple polygon can be determined. Pick's Theorem states:
    
        // Area=𝐼+𝐵/ 2 − 1

        long long I = (A-B+2)/2;
        
        return I;
        
    }
};
