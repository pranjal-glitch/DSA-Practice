class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();

        int totalSum = 0;
        for(int num : nums) {
            totalSum += num;
        }

        int leftSum = 0;
        vector<int> ans;

        for(int i = 0; i < n; i++) {
            totalSum -= nums[i];   // right sum

            ans.push_back(abs(leftSum - totalSum));

            leftSum += nums[i];
        }

        return ans;
    }
};
