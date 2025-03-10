// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/

class Solution {
public:
    int n ;
    int find_left_most(vector<int> &nums , int target)
    {
        int l = 0 ;
        int r = n-1 ;

        int left_most = -1 ;

        while(l <= r)
        {
            int mid = l + (r-l)/2 ;

            if(nums[mid] == target)
            {
                left_most = mid ;  // assuming its our target
                r = mid - 1 ;  // look more on left
            }
            else if(nums[mid] < target)
            {
                l = mid+1 ;
            }
            else
            {
                r = mid-1 ;
            }
        }
        return left_most ;
    }

    int find_right_most(vector<int> &nums , int target)
    {
        int l = 0 ; 
        int r = n-1 ;

        int right_most = -1 ;

        while(l <= r)
        {
            int mid = l + (r-l)/2 ;

            if(nums[mid] == target)
            {
                right_most = mid ;  // assuming its our right most
                l = mid+1 ;   // searching in right most
            }

            else if(nums[mid] < target)
            {
                l = mid+1 ;
            }

            else 
            {
                r = mid-1 ;
            }
        }
        return right_most ;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        n = nums.size() ;

        int left_most = find_left_most(nums , target) ;

        int right_most = find_right_most(nums , target) ;

        return {left_most , right_most} ;
    }
};
