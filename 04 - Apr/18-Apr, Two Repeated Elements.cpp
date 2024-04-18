//User function template for C++

class Solution {
  public:
    //Function to find two repeated elements.
    vector<int> twoRepeated (int arr[], int n) {
        vector<int>res;
        long long sum = (long long)n*(n+1)/2;;
        long long sum_squares = (long long)n*(n+1)*(2*n+1)/6;
        long long org_sum = 0;
        long long org_sum_squares = 0;
        
        for(int i = 0; i < n+2; i++) {
            int x = arr[i];
            org_sum += (long long)x;
            org_sum_squares += (long long)x*x;
        }
        
        long long x_plus_y = (long long)org_sum - sum;
        long long xs_plus_ys = (long long)org_sum_squares - sum_squares;
        long long x_plus_ys = (long long)x_plus_y*x_plus_y;
        long long prod_twice = (long long)x_plus_ys - xs_plus_ys;
        // long long xs_minus_ys = xs_plus_ys - prod_four;
        long long x_minus_y = sqrt(xs_plus_ys - prod_twice);
        long long x = (x_plus_y+x_minus_y)/2;
        long long y = (x_plus_y-x_minus_y)/2;
        // cout<<x_plus_y<<".  "<<xs_plus_ys<<".  "<<x_plus_ys<<".  "<<prod_twice<<endl;
        // cout<<x_minus_y<<endl;
        
        bool one = false, two = false;
        for(int i = 0; i < n+2; i++) {
            if(arr[i] == x && one) {
                res.push_back(x);
                res.push_back(y);
                return res;
            } else if(arr[i] == x) {
                one = true;
            }
            
            if(arr[i] == y && two) {
                res.push_back(y);
                res.push_back(x);
                return res;
            } else if(arr[i] == y) {
                two = true;
            }
        }
        
        return res;
    }
};
