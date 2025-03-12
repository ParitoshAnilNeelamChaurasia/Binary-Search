// https://leetcode.com/problems/guess-number-higher-or-lower/description/

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int f(int l , int r)
    {
        while(l <= r)
        {
            int mid = l + (r-l)/2 ;

            int val = guess(mid) ;

            if(val == -1)
            {
                r = mid-1 ;
            }

            else if(val == 1)
            {
                l = mid+1 ;
            }
            else
            {
                return mid ;
            }
        }
        return -1 ;
    }
    int guessNumber(int n) {
        return f(0 , n) ;
    }
};
