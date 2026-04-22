/*
Problem: Sum of Maximum and Minimum of all Subarrays of Size K
Platform: GFG / Coding Ninjas

Approach:

* Use sliding window + deque
* Maintain:

  * deque maxi → decreasing order (for max)
  * deque mini → increasing order (for min)
* Front of deque always stores index of max/min element

Time Complexity: O(n)
Space Complexity: O(k)
*/

#include <bits/stdc++.h>
using namespace std;

long long sumOfMaxAndMin(vector<int>& nums, int n, int k) {
deque<int> maxi;
deque<int> mini;

```
// First window
for (int i = 0; i < k; i++) {
    while (!maxi.empty() && nums[maxi.back()] <= nums[i])
        maxi.pop_back();

    while (!mini.empty() && nums[mini.back()] >= nums[i])
        mini.pop_back();

    maxi.push_back(i);
    mini.push_back(i);
}

long long ans = nums[maxi.front()] + nums[mini.front()];

// Remaining windows
for (int i = k; i < n; i++) {

    // Remove out-of-window indices
    while (!maxi.empty() && maxi.front() <= i - k)
        maxi.pop_front();

    while (!mini.empty() && mini.front() <= i - k)
        mini.pop_front();

    // Add new element
    while (!maxi.empty() && nums[maxi.back()] <= nums[i])
        maxi.pop_back();

    while (!mini.empty() && nums[mini.back()] >= nums[i])
        mini.pop_back();

    maxi.push_back(i);
    mini.push_back(i);

    ans += nums[maxi.front()] + nums[mini.front()];
}

return ans;
```

}
