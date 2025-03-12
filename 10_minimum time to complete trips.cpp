// https://leetcode.com/problems/minimum-time-to-complete-trips/description/

#define ll long long

class Solution {
public:

    bool possible(vector<int> &time , ll given_time , int totalTrips)
    {
      ll actual_trips = 0 ;

      for(auto &it : time)
      {
        // for getting number of trips  === >>> 

        // given time = 3

        // (3/1 + 3/2 + 3/3) => (3 + 1 + 1) => 5
        actual_trips += given_time/it ;
      }

      return actual_trips >= totalTrips ;

    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        ll n = time.size() ;

        ll l = 1 ;

        // upper bound because => its the maximum time in which trips can be completed 
        ll r = (ll)*min_element(time.begin() , time.end()) * totalTrips ;

        ll sum = 0 ;

        while(l < r)
        {
            ll mid = l + (r-l)/2 ;

            if(possible(time , mid , totalTrips))
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
