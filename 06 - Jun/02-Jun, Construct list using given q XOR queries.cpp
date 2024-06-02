
class Solution {
public:
    std::vector<int> constructList(int q, std::vector<std::vector<int>>& queries) {
        int xr = 0;
        std::vector<int> results;
        for (int i = q - 1; i >= 0; --i) {
            if (queries[i][0] == 0) {
                results.push_back(queries[i][1] ^ xr);
            } else {
                xr ^= queries[i][1];
            }
        }
        
        results.push_back(xr);
        
        std::sort(results.begin(), results.end());
        
        return results;
    }
};
