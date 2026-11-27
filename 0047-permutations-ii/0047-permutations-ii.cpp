
class Solution {
public:

    vector<vector<int>> permuteUnique(vector<int>& nums) {

        // Store unique permutations
        set<vector<int>> st;

        sort(nums.begin(), nums.end());

        do {
            st.insert(nums);
        }
        while (next_permutation(nums.begin(), nums.end()));

        // Convert set into vector of vectors
        vector<vector<int>> ans(st.begin(), st.end());

        return ans;
    }
};
