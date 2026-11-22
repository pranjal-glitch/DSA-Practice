class Solution {
public:
    int heightChecker(vector<int>& heights) {

        int n = heights.size();

        // Make a copy of original array
        vector<int> expected = heights;

        // Sort expected array using selection sort
        for(int i = 0; i < n - 1; i++) {

            int minIndex = i;

            for(int j = i + 1; j < n; j++) {
                if(expected[j] < expected[minIndex]) {
                    minIndex = j;
                }
            }

            swap(expected[i], expected[minIndex]);
        }
        // Count mismatches
        int count = 0;

        for(int i = 0; i < n; i++) {
            if(heights[i] != expected[i]) {
                count++;
            }
        }
        return count;
    }
};
