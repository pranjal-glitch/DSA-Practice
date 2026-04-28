/*
Problem: Wave Print of Matrix
Platform: Code360

Approach:

* Traverse column-wise
* Even column → top to bottom
* Odd column → bottom to top

Time Complexity: O(n * m)
Space Complexity: O(1) (excluding output)
*/

vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols) {

```
vector<int> ans;

for (int col = 0; col < mCols; col++) {

    if (col % 2 == 0) {
        // top → bottom
        for (int row = 0; row < nRows; row++) {
            ans.push_back(arr[row][col]);
        }
    } else {
        // bottom → top
        for (int row = nRows - 1; row >= 0; row--) {
            ans.push_back(arr[row][col]);
        }
    }
}

return ans;
```

}
