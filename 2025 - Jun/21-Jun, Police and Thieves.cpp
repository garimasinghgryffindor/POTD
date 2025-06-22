class Solution {
  public:
    int catchThieves(vector<char> &arr, int k) {
        int res = 0;
        vector<int>police, thieve;
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] == 'P') {
                police.push_back(i);
            } else {
                thieve.push_back(i);
            }
        }
        
        int i = 0, j = 0;
        while(i < police.size() && j < thieve.size()) {
            if(abs(police[i] - thieve[j]) <= k) {
                res++;
                i++;
                j++;
            } else if(police[i] < thieve[j]) {
                i++;
            } else {
                j++;
            }
        }
        
        return res;
    }
};
