class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        // Queue stores all currently rotten oranges
        queue<pair<int, int>> q;

        // Count total fresh oranges
        int fresh = 0;

        // Find all rotten and fresh oranges
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                // Put all initially rotten oranges in queue
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }

                // Count fresh oranges
                if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        int minutes = 0;

        // Four possible directions
        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        // Continue while there are rotten oranges
        // and fresh oranges are still remaining
        while (!q.empty() && fresh > 0) {

            // Number of rotten oranges at the
            // beginning of this minute
            int size = q.size();

            // Process all oranges for this minute
            for (int i = 0; i < size; i++) {

                int r = q.front().first;
                int c = q.front().second;
                //Take the first orange from the queue, get its row and column, then remove it from the queue

                q.pop();

                // Check all four directions
                for (int d = 0; d < 4; d++) {

                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    // Check if neighbor is inside grid
                    // and is a fresh orange
                    if (nr >= 0 && nr < m &&
                        nc >= 0 && nc < n &&
                        grid[nr][nc] == 1) {

                        // Make it rotten
                        grid[nr][nc] = 2;

                        // One less fresh orange
                        fresh--;

                        // Add newly rotten orange
                        // for the next minute
                        q.push({nr, nc});
                    }
                }
            }

            // One complete BFS level = one minute
            minutes++;
        }

        // Fresh oranges are still left,
        // so they can never become rotten
        if (fresh > 0)
            return -1;

        return minutes;
    }
};