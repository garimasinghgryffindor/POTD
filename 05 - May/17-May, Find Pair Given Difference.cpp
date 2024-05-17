
class Solution {
  public:
    int findPair(int n, int x, vector<int> &arr) {
        sort(arr.begin(), arr.end());
        int i = 0, j = 1;
    
        // Loop through the array
        while (i < n && j < n) {
            if (i != j && abs(arr[j] - arr[i]) == x) {
                return 1;
            } else if (abs(arr[j] - arr[i]) < x) {
                j++;
            } else {
                i++;
                if (i == j) j++;
            }
        }
        
        // If no such pair is found, return -1
        return -1;
    }
};
