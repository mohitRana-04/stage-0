class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // linear seach On^2

        // binary search
        // n* logn => n rows and binary search on each row

        // remember down and left
        int n = matrix.size(); // row
        int m = matrix[0].size(); // column

        int i = 0, j = m-1;

        while(i<n && j>=0){
            if(matrix[i][j] == target ) return true;

            else if(matrix[i][j] > target){
                j--;
            }
            else{
                i++;
            }
        }
        return false;

    }
};