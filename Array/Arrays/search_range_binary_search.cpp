/*
Problem: Find First and Last Position of Element in Sorted Array
Platform: LeetCode

Approach:

* Use Binary Search twice:

  1. Find first occurrence
  2. Find last occurrence
* Modify search space when target is found

Time Complexity: O(log n)
Space Complexity: O(1)
*/

class Solution {
public:
int firstOcc(vector<int>& nums, int target) {
int start = 0, end = nums.size() - 1;
int ans = -1;

```
    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (nums[mid] == target) {
            ans = mid;
            end = mid - 1;
        }
        else if (nums[mid] < target) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }
    return ans;
}

int lastOcc(vector<int>& nums, int target) {
    int start = 0, end = nums.size() - 1;
    int ans = -1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (nums[mid] == target) {
            ans = mid;
            start = mid + 1;
        }
        else if (nums[mid] < target) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }
    return ans;
}

vector<int> searchRange(vector<int>& nums, int target) {
    return {firstOcc(nums, target), lastOcc(nums, target)};
}
```

};
