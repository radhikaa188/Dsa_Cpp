class Solution {
public:
    void dfs(int startingNode, vector<int>adjList[],
             vector<int>&visited) {
                visited[startingNode] = 1;
                    for(auto it: adjList[startingNode]){
                       if(!visited[it]) dfs(it, adjList, visited);
                    }
                }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> adjList[n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }
        vector<int> vis(n,0);
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, adjList, vis);
                count++;
            }
        }
        return count;
    }
};