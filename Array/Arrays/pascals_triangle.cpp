/*
Problem: Pascal's Triangle
Platform: LeetCode

Approach:

* Each row starts and ends with 1
* Middle elements:
  row[j] = prev_row[j-1] + prev_row[j]

Time Complexity: O(n^2)
Space Complexity: O(n^2)
*/

class Solution {
public:
vector<vector<int>> generate(int numRows) {

```
    vector<vector<int>> ans;

    for(int i = 0; i < numRows; i++){
        vector<int> row(i + 1);

        row[0] = row[i] = 1;

        for(int j = 1; j < i; j++){
            row[j] = ans[i-1][j-1] + ans[i-1][j];
        }

        ans.push_back(row);
    }

    return ans;
}
```

};
