/*
Problem: First Negative Integer in Every Window of Size K
Platform: GFG / Coding Ninjas

Approach:

* Use sliding window + deque
* Store indices of negative numbers
* Front of deque = first negative in current window

Time Complexity: O(n)
Space Complexity: O(k)
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> firstNegativeInteger(vector<int> &arr, int k, int n) {

```
deque<int> dq;
vector<int> ans;

// Process first window
for(int i = 0; i < k; i++){
    if(arr[i] < 0){
        dq.push_back(i);
    }
}

// Store answer for first window
ans.push_back(dq.empty() ? 0 : arr[dq.front()]);

// Process remaining windows
for(int i = k; i < n; i++){

    // Remove out-of-window indices
    if(!dq.empty() && dq.front() <= i - k){
        dq.pop_front();
    }

    // Add current element if negative
    if(arr[i] < 0){
        dq.push_back(i);
    }

    // Store result
    ans.push_back(dq.empty() ? 0 : arr[dq.front()]);
}

return ans;
```

}
