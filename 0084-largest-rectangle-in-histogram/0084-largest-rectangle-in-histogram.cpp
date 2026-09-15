#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Next Smaller Element (index)
    vector<int> nextSmaller(vector<int>& arr, int n) {
        stack<int> s;
        vector<int> ans(n);

        for(int i = n - 1; i >= 0; i--) {
            while(!s.empty() && arr[s.top()] >= arr[i]) {
                s.pop();
            }
            ans[i] = s.empty() ? n : s.top();
            s.push(i);
        }
        return ans;
    }

    // Previous Smaller Element (index)
    vector<int> prevSmaller(vector<int>& arr, int n) {
        stack<int> s;
        vector<int> ans(n);

        for(int i = 0; i < n; i++) {
            while(!s.empty() && arr[s.top()] >= arr[i]) {
                s.pop();
            }
            ans[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }
        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> next = nextSmaller(heights, n);
        vector<int> prev = prevSmaller(heights, n);

        int maxArea = 0;

        for(int i = 0; i < n; i++) {
            int height = heights[i];
            int width = next[i] - prev[i] - 1;

            int area = height * width;
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};