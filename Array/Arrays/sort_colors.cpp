/*
Problem: Sort Colors
Approach 1: Selection Sort (Brute Force)

Time Complexity: O(n^2)
Space Complexity: O(1)
*/

class Solution {
public:
void sortColors(vector<int>& nums) {

```
    int n = nums.size();

    for(int i = 0; i < n - 1; i++) {
        int minIndex = i;

        for(int j = i + 1; j < n; j++) {
            if(nums[j] < nums[minIndex]) {
                minIndex = j;
            }
        }

        swap(nums[i], nums[minIndex]);
    }
}
```

};
