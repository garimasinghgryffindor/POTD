class Solution {
  public:
    int countIntervals(vector<int>&s, double mid) {
        int cnt = 0;
        for(int i = 0; i < s.size()-1; i++) {
            cnt += static_cast<int>(ceil((s[i+1]-s[i])/mid)) - 1;
        }
        return cnt;
    }
    
    double findSmallestMaxDist(vector<int> &stations, int k) {
        int n = stations.size();
        sort(stations.begin(), stations.end());
        double l = 1e-9, r = stations[n-1]-stations[0];
        
        while((r - l) > 1e-6) {
            double mid = l + (r - l)/2.0;
            int cnt = countIntervals(stations, mid);
            if(cnt > k) {
                l = mid;
            } else {
                r = mid;
            }
        }
        
        return r;
    }
};
