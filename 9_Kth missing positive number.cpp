// https://leetcode.com/problems/kth-missing-positive-number/

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size() ;

        int l = 0 ; 
        int r = n-1 ;

        int mid = -1 ;

        while(l <= r)
        {
            mid = l  + (r-l)/2 ;

            int miss_till_end = arr[mid] - (mid + 1); // formula to find missing number till that particular index

            if(miss_till_end < k)
            {
                l = mid+1 ;
            }
            else
            {
                r = mid-1 ;
            }
        }
        return l + k;

    }
};
