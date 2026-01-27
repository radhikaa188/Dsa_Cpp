class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>& visit,
             vector<vector<int>>&grid, int delrow[],
             int delcol[], int n, int m) {
        visit[row][col] = 1;
        for (int i = 0; i < 4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                grid[nrow][ncol] == 1 && !visit[nrow][ncol]) {
                dfs(nrow, ncol, visit, grid, delrow, delcol, n, m);
            }
        }
    }

public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        vector<vector<int>> visit(n, vector<int>(m, 0));
        for (int i = 0; i < m; i++) {
            if (grid[0][i] == 1 && !visit[0][i]) {
                dfs(0, i, visit, grid, delrow, delcol, n, m);
            }
            if (grid[n - 1][i] == 1 && !visit[n - 1][i]) {
                dfs(n-1, i, visit, grid, delrow, delcol, n, m);
            }
        }
        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 1 && !visit[i][0]) {
                dfs(i, 0, visit, grid, delrow, delcol, n, m);
            }
            if (grid[i][m - 1] == 1 && !visit[i][m - 1]) {
                dfs(i, m-1, visit, grid, delrow, delcol, n, m);
            }
        }
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] != visit[i][j]) {
                    count++;
                }
            }
        }
        return count;
    }
};