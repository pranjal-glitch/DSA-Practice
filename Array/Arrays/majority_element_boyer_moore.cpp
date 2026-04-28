/*
Problem: Majority Element
Platform: LeetCode

Approach: Boyer-Moore Voting Algorithm

* Maintain a candidate and a count
* If count becomes 0 → choose new candidate
* Increment if same, decrement if different

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
int majorityElement(vector<int>& nums) {
int count = 0;
int candidate = 0;

```
    for(int num : nums) {

        if(count == 0) {
            candidate = num;
        }

        if(num == candidate) {
            count++;
        } else {
            count--;
        }
    }

    return candidate;
}
```

};
