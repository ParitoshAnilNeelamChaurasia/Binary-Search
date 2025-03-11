// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/

class Solution {
public:
    int n ;

    int f(vector<int> &nums)
    {  
        int l = 0 ;
        int r = n - 1 ;

        int mn = -1 ;
        while(l < r)
        {
            int mid = l + (r-l)/2 ;

            if(nums[mid] > nums[r])
            {
                l = mid+1 ;
            }
            else
            {
                r = mid;
            }
        }
        return nums[r] ;
    }
    int findMin(vector<int>& nums) {
        n = nums.size() ;

        int mn = f(nums) ;

        return mn ;
    }
};

