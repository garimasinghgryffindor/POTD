// User function template for C++

class Solution {
  public:
    long long pairAndSum(int n, long long arr[]) {
        // code here
        long long sum = 0;
        for(int i = 0; i < 32; i++) {
            long long count = 0;
            for(int j = 0; j < n; j++) {
                if(arr[j] & (1<<i)) {
                    count++;
                }
            }
        
            long long total_pairs = count*(count-1)/2;
            long long temp = (1<<i)*total_pairs;
            sum += temp;
        }
        
        return sum;
    }
};
