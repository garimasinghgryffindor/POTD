// User function Template for C++

class Solution {
  public:
    int rectanglesInCircle(int r) {
        int count = 0;
        int diameter = 2*r;
        int d_square = diameter*diameter;
        for(int i = 1; i < 2*r; i++) {
            for(int j = 1; j < 2*r; j++) {
                int perpendicular_square = i*i;
                int base_square = j*j;
                if(perpendicular_square+base_square <= d_square) { 
                    count++;
                }
            }
        }
        
        return count;
    }
};
