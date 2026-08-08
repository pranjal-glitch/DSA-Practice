class Solution {
private:
    void dfs(vector<vector<int>>& image, int r, int c,
             int oldColor, int newColor) {

        int m = image.size();
        int n = image[0].size();

        // Boundary check
        if (r < 0 || r >= m || c < 0 || c >= n)
            return;

        // If the pixel is not of the original color,
        // we don't need to visit it.
        if (image[r][c] != oldColor)
            return;

        // Change the color
        image[r][c] = newColor;

        // Visit all 4 directions
        dfs(image, r + 1, c, oldColor, newColor); // Down
        dfs(image, r - 1, c, oldColor, newColor); // Up
        dfs(image, r, c + 1, oldColor, newColor); // Right
        dfs(image, r, c - 1, oldColor, newColor); // Left
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image,
                                   int sr, int sc, int color) {

        int oldColor = image[sr][sc];

        // If both colors are same, no changes are needed
        if (oldColor == color)
            return image;

        dfs(image, sr, sc, oldColor, color);

        return image;
    }
};