/*
Problem: Spiral Matrix Traversal
Platform: Code360 / LeetCode

Approach:

* Maintain 4 boundaries:
  top, bottom, left, right
* Traverse:

  1. Top row → left to right
  2. Right column → top to bottom
  3. Bottom row → right to left
  4. Left column → bottom to top
* Shrink boundaries after each step

Time Complexity: O(n * m)
Space Complexity: O(1) (excluding output)
*/

vector<int> spiralPathMatrix(vector<vector<int>> matrix, int n, int m) {

```
vector<int> result;

int top = 0, bottom = n - 1;
int left = 0, right = m - 1;

while (top <= bottom && left <= right) {

    // Top row
    for (int i = left; i <= right; i++) {
        result.push_back(matrix[top][i]);
    }
    top++;

    // Right column
    for (int i = top; i <= bottom; i++) {
        result.push_back(matrix[i][right]);
    }
    right--;

    // Bottom row
    if (top <= bottom) {
        for (int i = right; i >= left; i--) {
            result.push_back(matrix[bottom][i]);
        }
        bottom--;
    }

    // Left column
    if (left <= right) {
        for (int i = bottom; i >= top; i--) {
            result.push_back(matrix[i][left]);
        }
        left++;
    }
}

return result;
```

}
