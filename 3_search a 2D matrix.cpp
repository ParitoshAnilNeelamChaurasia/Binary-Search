// https://leetcode.com/problems/search-a-2d-matrix/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size() ;
        int n = matrix[0].size() ;

        int i = 0 ;
        int j = n-1 ;

        while(i < m && j >= 0)
        {
            if(matrix[i][j] > target)
            {
                j-- ;
            }

            else if(matrix[i][j] < target)
            {
                i++ ;
            }

            else
            {
                return true ;
            }
        }
        return false ;
    }
};
