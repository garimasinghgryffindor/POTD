// User function Template for C++

class Solution {
  public:
    
    int minSteps(int d) {
        int steps = 0;
        int sum = 0;
    
        // Keep adding steps until the sum becomes greater than or equal to the destination
        while (sum < d || (sum - d) % 2 != 0) {
            steps++;
            sum += steps;
        }
    
        return steps;
    }
};
