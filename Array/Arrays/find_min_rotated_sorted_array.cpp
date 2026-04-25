/*
Problem: Find Minimum in Rotated Sorted Array
Platform: LeetCode

Approach:

* Use Binary Search
* Compare mid with end:
  if nums[mid] < nums[end] → minimum is in left half (including mid)
  else → minimum is in right half

Time Complexity: O(log n)
Space Complexity: O(1)
*/

class Solution {
public:
int findMin(vector<int>& nums) {

```
    int start = 0;
    int end = nums.size() - 1;

    while (start < end) {
        int mid = start + (end - start) / 2;

        if (nums[mid] < nums[end]) {
            end = mid;
        } else {
            start = mid + 1;
        }
    }

    return nums[start];
}
```

};
