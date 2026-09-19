class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        unordered_map<int, int> pos;

        // Store value -> index
        for (int i = 0; i < nums.size(); i++) {
            pos[nums[i]] = i;
        }
        // Apply operations
        for (auto &op : operations) {
            int oldVal = op[0];
            int newVal = op[1];

            int idx = pos[oldVal];

            nums[idx] = newVal;

            // Update the position map
            pos[newVal] = idx;
            pos.erase(oldVal);
        }

        return nums;
    }
};