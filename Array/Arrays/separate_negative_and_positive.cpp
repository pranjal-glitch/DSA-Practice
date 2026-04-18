/*
Problem: Separate Negative and Positive Numbers
Platform: Coding Ninjas / Practice

Approach:

* Use Two Pointer Technique
* Start with left at 0 and right at end
* If left is negative → move ahead
* If right is positive → move backward
* Else → swap both

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> separateNegativeAndPositive(vector<int> &nums){

```
int left = 0;
int right = nums.size() - 1;

while(left <= right){
    
    if(nums[left] < 0){
        left++;
    }
    else if(nums[right] >= 0){
        right--;
    }
    else{
        swap(nums[left], nums[right]);
        left++;
        right--;
    }
}

return nums;


}
