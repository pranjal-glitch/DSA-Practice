class Solution {
public:

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> s;
        int maxArea = 0;

        for(int i = 0; i <= n; i++) {

            int currHeight;

            // Instead of using ?, we use normal if-else
            if(i == n) {
                currHeight = 0;   // fake height at the end
            } else {
                currHeight = heights[i];
            }

            // If current height is smaller → calculate area
            while(!s.empty() && currHeight < heights[s.top()]) {

                int h = heights[s.top()];
                s.pop();

                int width;

                if(s.empty()) {
                    width = i;
                } else {
                    width = i - s.top() - 1;
                }

                maxArea = max(maxArea, h * width);
            }

            s.push(i);
        }

        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {

        int n = matrix.size();
        if(n == 0) return 0;

        int m = matrix[0].size();

        vector<int> heights(m, 0);
        int maxArea = 0;

        for(int i = 0; i < n; i++) {

            for(int j = 0; j < m; j++) {

                if(matrix[i][j] == '1') {
                    heights[j] = heights[j] + 1;
                } else {
                    heights[j] = 0;
                }
            }

            maxArea = max(maxArea, largestRectangleArea(heights));
        }

        return maxArea;
    }
};