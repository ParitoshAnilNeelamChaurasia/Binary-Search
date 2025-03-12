// https://leetcode.com/problems/koko-eating-bananas/description/

class Solution {
public:
    int n ;

    bool is_possible(vector<int>& piles, int h , int time_taken)
    {
        int hrs_required_for_time_taken = 0 ;

        for(auto &it : piles)
        {
            hrs_required_for_time_taken += (it / time_taken) ;

            if(it % time_taken != 0)
            {
                hrs_required_for_time_taken++ ;
            }
        }

        return hrs_required_for_time_taken <= h ;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        n = piles.size() ;

        // int l = 0 ; => must not take because when mid == 0 => than it gaves runtime error

        int l = 1 ;

        // if taken 

        // int r = *max_element(piles.begin() , piles.end())    => than it gaves wrong ans on test case 2nd

        // because maximum to eat = 20 =? which didn't satisfies the situation
        int r = *max_element(piles.begin() , piles.end())  ;

        while(l < r)
        {
            int mid = l + (r-l)/2 ;

            if(is_possible(piles,h,mid))
            {
                r = mid ;
            }
            else
            {
                l = mid+1 ;
            }
        }
        return l ;
    }
};
