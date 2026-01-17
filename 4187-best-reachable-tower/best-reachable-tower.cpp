class Solution {
public:
    vector<int> bestTower(vector<vector<int>>& towers, vector<int>& center,
                          int radius) {
        int maxQuality = INT_MIN;
        int index = -1;
        for (int i = 0; i < towers.size(); i++) {
            if (abs(towers[i][0] - center[0]) + abs(towers[i][1] - center[1]) <=
                radius) {
                if (towers[i][2] == maxQuality) {
                    if (towers[i][0] < towers[index][0] ||
                        (towers[i][0] == towers[index][0] &&
                         towers[i][1] < towers[index][1])) {
                        index = i;
                    }
                } else {
                    if (towers[i][2] > maxQuality) {
                        maxQuality = towers[i][2];
                        index = i;
                    }
                }
            }
        }
        vector<int> res(2, -1);
        if (index != -1) {
            for (int i = 0; i < res.size(); i++) {
                res[i] = towers[index][i];
            }
        }
        return res;
    }
};