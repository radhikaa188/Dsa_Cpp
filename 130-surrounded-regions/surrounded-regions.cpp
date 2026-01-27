class Solution {
private:
    // dfs
    void dfs(int row, int col, vector<vector<int>>& visit,
             vector<vector<char>>& board, int delrow[],
             int delcol[], int n, int m) {

        visit[row][col] = 1;

        for (int i = 0; i < 4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                board[nrow][ncol] == 'O' && !visit[nrow][ncol]) {
                dfs(nrow, ncol, visit, board, delrow, delcol, n, m);
            }
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        vector<vector<int>> visited(n, vector<int>(m, 0));

        // first and last row
        for (int i = 0; i < m; i++) {
            if (board[0][i] == 'O' && !visited[0][i]) {
                dfs(0, i, visited, board, delrow, delcol, n, m);
            }
            if (board[n - 1][i] == 'O' && !visited[n - 1][i]) {
                dfs(n - 1, i, visited, board, delrow, delcol, n, m);
            }
        }

        // first and last column
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O' && !visited[i][0]) {
                dfs(i, 0, visited, board, delrow, delcol, n, m);
            }
            if (board[i][m - 1] == 'O' && !visited[i][m - 1]) {
                dfs(i, m - 1, visited, board, delrow, delcol, n, m);
            }
        }
        // replace
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] && board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};