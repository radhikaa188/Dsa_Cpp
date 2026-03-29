class Solution {
public:
    class Disjoint {
    public:
        vector<int> rank, parent, size;

        // constructor
        Disjoint(int n) {
            rank.resize(n + 1, 0);
            parent.resize(n + 1);
            size.resize(n + 1, 1);
            for (int i = 0; i <= n; i++) {
                parent[i] = i;
            }
        }
        // ultimate_parent
        int findUParent(int node) {
            if (parent[node] == node)
                return node;
            return parent[node] = findUParent(parent[node]);
        }
        void unionByRank(int u, int v) {
            int ulp_u = findUParent(u);
            int ulp_v = findUParent(v);
            if (ulp_u == ulp_v)
                return;
            if (rank[ulp_u] > rank[ulp_v]) {
                parent[ulp_v] = ulp_u;
            } else if (rank[ulp_v] > rank[ulp_u]) {
                parent[ulp_u] = ulp_v;
            } else {
                parent[ulp_u] = ulp_v;
                rank[ulp_v]++;
            }
        }
        void unionBySize(int u, int v) {
            int ulp_u = findUParent(u);
            int ulp_v = findUParent(v);
            if (ulp_u == ulp_v)
                return;
            if (size[ulp_u] > size[ulp_v]) {
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            } else {
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            }
        }
    };
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        Disjoint ds(n * m);
        int mx=0;
        int rowarr[] = {-1, 0, 1, 0};
        int colarr[] = {0, 1, 0, -1};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0)
                    continue;
                for (int k = 0; k < 4; k++) {
                    int newR = i + rowarr[k];
                    int newC = j + colarr[k];
                    if (newR >= 0 && newR < n && newC >= 0 && newC < m) {
                        if (grid[newR][newC] == 1) {
                            int node = (i * m) + j;
                            int adjnode = (newR * m) + newC;
                            ds.unionBySize(node, adjnode);
                        }
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                set<int>s;
                if (grid[i][j] == 0) {
                    for (int k = 0; k < 4; k++) {
                        int newRow = rowarr[k] + i;
                        int newCol = colarr[k] + j;
                        if (newRow >= 0 && newRow < n && newCol >= 0 &&
                            newCol < m && grid[newRow][newCol] == 1){
                                int cnode= (newRow*m)+newCol;
                                s.insert(ds.findUParent(cnode));
                            }
                    }
                    int size=0;
                    for(auto it: s){
                        size+= ds.size[it];
                    }
                    mx= max(mx, size+1);
                }
            }
        }
        for(int i=0; i<n*m; i++){
            mx=max(mx, ds.size[ds.findUParent(i)]);
        }
        return mx;
    }
};