class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0)
            return false;
        int rows = matrix.size(), cols  = matrix[0].size();
        int i = 0, j = 0;
        for (i = 0; i < rows; i++) {
            for (j = 0; j < cols; j++) {
                if (matrix[i][j] == target)
                    return true;
            }
        }
        return false;
    }
};