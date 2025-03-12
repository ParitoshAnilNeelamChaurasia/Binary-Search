// https://leetcode.com/problems/search-in-rotated-sorted-array/description/

class Solution {
public:

    int find_pivot(vector<int> &nums , int n)
    {
        int l = 0 ;
        int r = n-1 ;

        while(l < r)
        {
            int mid = l + (r-l)/2 ;  

            if(nums[mid] > nums[r])
            {
                l = mid + 1;
            }
            else
            {
                r = mid ;
            }
        }
        return r ;
    }

    int binary(int l , int r ,vector<int> &nums , int target)
    {
        int n = nums.size() ;

        int ind = -1 ;

        while(l <= r)
        {
            int mid = (l+r)/2 ;

            if(nums[mid] < target)
            {
                l = mid+1 ;
            }
            else if(nums[mid] > target)
            {
                r = mid-1 ;
            }
            else
            {
                ind = mid ;
                break ;
            }
        }
        return ind ;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size() ;

        int pivot_index = find_pivot(nums , n) ;

        int idx = binary(0 , pivot_index-1 , nums , target) ;

        if(idx != -1)
        {
            return idx ;
        }
        
        idx = binary(pivot_index , n-1 , nums , target) ;

        return idx ;
    }
};
