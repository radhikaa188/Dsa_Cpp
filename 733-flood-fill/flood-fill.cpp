class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int n = image.size();
        int m = image[0].size();
        queue<pair<int, int>> q;

        int originalColour = image[sr][sc];
        if (originalColour == color)
            return image;

        q.push({sr, sc});
        image[sr][sc] = color;

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    image[nrow][ncol] == originalColour) {
                    q.push({nrow, ncol});
                    image[nrow][ncol] = color;
                }
            }
        }
        return image;
    }
};