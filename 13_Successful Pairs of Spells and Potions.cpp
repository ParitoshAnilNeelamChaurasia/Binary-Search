
// https://leetcode.com/problems/successful-pairs-of-spells-and-potions/description/


#define ll long long

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = potions.size();
        vector<int> ans;

        sort(potions.begin(), potions.end());
        int maxPotionValue = potions[n - 1];

        for (int i = 0; i < spells.size(); ++i) 
        {
            int spell = spells[i];
            ll min_potion = (success + spell - 1) / spell; // equivalent to ceil((1.0*success)/spell) but avoids floating-point

            if (min_potion > maxPotionValue) {
                ans.push_back(0);
                continue;
            }

            auto it = lower_bound(potions.begin(), potions.end(), min_potion);
            int ind = it - potions.begin();
            int count = n - ind;

            ans.push_back(count);
        }
        return ans;
    }
};
