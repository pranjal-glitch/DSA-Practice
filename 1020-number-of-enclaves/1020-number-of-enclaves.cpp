class Solution {
public:

    void dfs(vector<vector<int>>& grid,
             vector<vector<int>>& visited,
             int i, int j) {

        int n = grid.size();
        int m = grid[0].size();

        if (i < 0 || i >= n || j < 0 || j >= m)
            return;

        if (grid[i][j] == 0 || visited[i][j])
            return;

        visited[i][j] = 1;

        dfs(grid, visited, i + 1, j);
        dfs(grid, visited, i - 1, j);
        dfs(grid, visited, i, j + 1);
        dfs(grid, visited, i, j - 1);
    }

    int numEnclaves(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));

        // Top and bottom boundaries
        for (int j = 0; j < m; j++) {

            if (grid[0][j] == 1)
                dfs(grid, visited, 0, j);

            if (grid[n - 1][j] == 1)
                dfs(grid, visited, n - 1, j);
        }

        // Left and right boundaries
        for (int i = 0; i < n; i++) {

            if (grid[i][0] == 1)
                dfs(grid, visited, i, 0);

            if (grid[i][m - 1] == 1)
                dfs(grid, visited, i, m - 1);
        }
        // Count enclosed land cells
        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (grid[i][j] == 1 && visited[i][j] == 0)
                    count++;
            }
        }
        return count;
    }
};