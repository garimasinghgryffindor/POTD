class Solution {
  public:
    // Function to count number of ways to reach the nth stair
    // when order does not matter.
    long long countWays(int n) {
        long long mx = n/2;
        if(n%2 == 1) {
            mx++;
        }
        long long normal = n;
        long long res = normal - mx + 1;
        return res;
    }
};
