/*
Problem: Search in Rotated Sorted Array
Platform: LeetCode

Approach:
- Use modified binary search
- At least one half is always sorted
- Check which half is sorted
- Decide where target lies

Time Complexity: O(log n)
Space Complexity: O(1)
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {

        int start = 0;
        int end = nums.size() - 1;

        while(start <= end){

            int mid = start + (end - start) / 2;

            if(nums[mid] == target){
                return mid;
            }

            // Left half sorted
            if(nums[start] <= nums[mid]){

                if(target >= nums[start] && target < nums[mid]){
                    end = mid - 1;
                }
                else{
                    start = mid + 1;
                }
            }

            // Right half sorted
            else{

                if(target > nums[mid] && target <= nums[end]){
                    start = mid + 1;
                }
                else{
                    end = mid - 1;
                }
            }
        }

        return -1;
    }
};
