class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<int, pair<int, int>>> q;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dis(n, vector<int>(m, 1e9));
        if(grid[0][0] == 1) return -1;
        if(n==1 && m==1) return 1;
        dis[0][0] = 0;
        q.push({0, {0, 0}});
        int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1};
        int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int row = it.second.first;
            int col = it.second.second;
            int distance = it.first;
            for (int i = 0; i < 8; i++) {
                int newR = row + dr[i];
                int newC = col + dc[i];
                if (newR >= 0 && newR < n && newC >= 0 && newC < m &&
                    grid[newR][newC] == 0 && (1 + distance) < dis[newR][newC]) {
                        dis[newR][newC] = 1 + distance;
                        if(newR == n-1 && newC == m-1) return (dis[newR][newC] + 1);
                        q.push({dis[newR][newC], {newR, newC}});
                }
            }
        }
        return -1;
    }
};