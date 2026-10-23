class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {

        int n = nums.size();

        // Step 1: Square all elements
        for(int i = 0; i < n; i++) {
            nums[i] = nums[i] * nums[i];
        }

        // Step 2: Sort using selection sort
        for(int i = 0; i < n - 1; i++) {

            int minIndex = i;

            for(int j = i + 1; j < n; j++) {
                if(nums[j] < nums[minIndex]) {
                    minIndex = j;
                }
            }

            swap(nums[i], nums[minIndex]);
        }

        return nums;
    }
};
