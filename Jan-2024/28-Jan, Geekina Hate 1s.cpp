// It is a universal fact that Geekina hates 1s however it is also known that Geekina loves the integers having atmost k 1s (set-bits) 
// in their binary representation. 

// Geekina demanded nth such non-negative number from Geek, and being a good friend of Geek, now it's your responsibility to tell him 
// that number.

// Note: The test cases are generated such that the answer always exists and will fit in the 64-bit data type.


class Solution {
  public:
    long long combination(long long n, long long r) {
        long long ans = 1;
        for(int i = 1; i <= r; i++) {
            ans = ans*(n-r+i)/i;
        }
        // cout<<ans<<"   ";
        return ans;
    }
    
    long long countUtils(long long num, long long k) {
        if(k == 0) return 1;
        if(num == 0) return 0;
        
        long long highestSetBit = log2(num);
        
        if(highestSetBit < k-1) return 0;
        
        //      when we are not incl the bit    when we are including it
        return (combination(highestSetBit, k) + countUtils((num^((long long)1<<highestSetBit)), k-1) );
    }
  
    long long countNumbers(long long num, long long k) {
        long long sum = 0;
        for(int i = 0; i <= k; i++) {
            sum+=countUtils(num, i);
        }
        return sum;
    }
  
    long long findNthNumber(int n, int k) {
        // code here
        long long low = 0, high = 1e18;
        // using binary search
        while(low < high) {
            long long mid = low + (high - low)/2;
            long long count = countNumbers(mid, k);
            if(count >= n) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        
        return low;
    }
};
