class Solution
{
    public:
        int maxSum(int n)
        {
            if(n == 0) return 0;
            int sum = n/2 + n/3 + n/4;
            if(sum < n) return n;
            
            return maxSum(n/2) + maxSum(n/3) + maxSum(n/4);
        }
};
