class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> visited(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    visited[i][j] = 2;
                } else {
                    visited[i][j] = 0;
                }
            }
        }
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        int tm = 0;
        while (!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int time = q.front().second;
            tm = max(tm, time);
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];
                if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n &&
                    visited[nrow][ncol] != 2 && grid[nrow][ncol] == 1) {
                    q.push({{nrow, ncol}, time + 1});
                    visited[nrow][ncol] = 2;
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (visited[i][j] != 2 && grid[i][j] == 1) {
                    return -1;
                }
            }
        }

        return tm;
    }
};