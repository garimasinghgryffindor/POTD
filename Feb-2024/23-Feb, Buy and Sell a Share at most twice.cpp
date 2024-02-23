
class Solution
{
    public:
        //User function Template for C++
        void recur(vector<int>&price, int idx, bool flag, int count, int&res, int curr) {
            if(idx == price.size()) return;
            if(idx == price.size()-1 && !flag) return;
            
            if(count == 2) return;
            
            if(!flag) {
                // you have to buy
                recur(price, idx+1, true, count, res, curr-price[idx]);
                recur(price, idx+1, false, count, res, curr);
            } else {
                // you have to sell`
                // sell this
                if(curr + price[idx] >= 0) {
                    res = max(res, curr+price[idx]);
                    recur(price, idx+1, false, count+1, res, curr+price[idx]);
                }
                // or sell next
                recur(price, idx+1, true, count, res, curr);
            }
        }
        
        // int maxProfit(vector<int>&price){
        //     int res = 0;
        //     bool flag = false;
        //     // flag = false : buy
        //     // flag = true  : sell
        //     int count = 0, curr = 0;
        //     recur(price, 0, flag, count, res, curr);
            
        //     return res;
        // }
        
        int maxProfit(vector<int>&prices){
            int n = prices.size();
            if (n <= 1) {
                return 0;
            }
        
            int buy1 = INT_MAX, buy2 = INT_MAX;
            int profit1 = 0, profit2 = 0;
        
            for (int i = 0; i < n; ++i) {
                // First transaction
                buy1 = min(buy1, prices[i]);
                profit1 = max(profit1, prices[i] - buy1);
        
                // Second transaction
                buy2 = min(buy2, prices[i] - profit1);
                profit2 = max(profit2, prices[i] - buy2);
            }
        
            return profit2;
        }
};
