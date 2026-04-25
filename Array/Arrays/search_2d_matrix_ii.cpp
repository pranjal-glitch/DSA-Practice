/*
Problem: Search a 2D Matrix II
Platform: LeetCode

Approach:

* Start from top-right corner
* If current element == target → return true
* If current element < target → move down
* If current element > target → move left

Time Complexity: O(n + m)
Space Complexity: O(1)
*/

class Solution {
public:
bool searchMatrix(vector<vector<int>>& matrix, int target) {

```
    int rows = matrix.size();
    int cols = matrix[0].size();

    int r = 0;
    int c = cols - 1;

    while(r < rows && c >= 0){
        int element = matrix[r][c];

        if(element == target){
            return true;
        }
        else if(element < target){
            r++;
        }
        else{
            c--;
        }
    }

    return false;
}
```

};
