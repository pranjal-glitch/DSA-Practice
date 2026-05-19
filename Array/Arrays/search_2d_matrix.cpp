/*
Problem: Search a 2D Matrix
Platform: LeetCode

Approach:
- Treat matrix as a sorted 1D array
- Apply binary search
- Convert 1D index → 2D coordinates

row = mid / cols
col = mid % cols

Time Complexity: O(log(m*n))
Space Complexity: O(1)
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int rows = matrix.size();
        int cols = matrix[0].size();

        int start = 0;
        int end = rows * cols - 1;

        while(start <= end){

            int mid = start + (end - start) / 2;

            int element = matrix[mid / cols][mid % cols];

            if(element == target){
                return true;
            }

            else if(element < target){
                start = mid + 1;
            }

            else{
                end = mid - 1;
            }
        }

        return false;
    }
};
