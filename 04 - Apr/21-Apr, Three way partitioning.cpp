//User function template for C++

class Solution{   
public:
    //Function to partition the array around the range such 
    //that array is divided into three parts.
    void threeWayPartition(vector<int>& array,int a, int b)
    {
        // Dutch's National Flag Algorithm
        int l = 0, r = array.size()-1;
        int mid = 0;
        while(mid <= r) {
            if(array[mid] < a) {
                swap(array[mid], array[l]);
                l++;
                mid++;
            } else if(array[mid] <= b) {
                mid++;
            } else {
                swap(array[mid], array[r]);
                r--;
            }
        }
        
    }
};
