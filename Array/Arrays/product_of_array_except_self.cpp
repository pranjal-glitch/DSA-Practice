/*
Problem: Product of Array Except Self
Platform: LeetCode

Approach:

* Use prefix and suffix multiplication
* Avoid division
* Store prefix in answer array
* Multiply with suffix while traversing from right

Time Complexity: O(n)
Space Complexity: O(1) (excluding output array)
*/

class Solution {
public:
vector<int> productExceptSelf(vector<int>& nums) {
int n = nums.size();
vector<int> ans(n, 1);

```
    // Prefix products
    for(int i = 1; i < n; i++) {
        ans[i] = ans[i - 1] * nums[i - 1];
    }

    // Suffix products
    int right = 1;
    for(int i = n - 1; i >= 0; i--) {
        ans[i] *= right;
        right *= nums[i];
    }

    return ans;
}
```

};
