class Solution {
public:
    int timer = 1;
    void dfs(int node, int parent, vector<int> &visit, int time[], int low[],
             vector<int>adj[], vector<vector<int>>& bridges) {
                visit[node]=1;
                time[node]=low[node]=timer;
                timer++;
                for(auto i: adj[node]){
                    if(i==parent) continue;
                    if(visit[i]==0){
                        dfs(i, node, visit, time, low, adj, bridges);
                        low[node]=min(low[node], low[i]);;
                        //bridge
                        if(time[node] < low[i]){
                            bridges.push_back({node, i});
                        }
                    }else{
                        low[node]=min(low[node], low[i]);
                    }
                }
             }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        for (auto it : connections) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<vector<int>> bridges;
        int time[n];
        int low[n];
        vector<int> visit(n, 0);
        dfs(0, -1, visit, time, low, adj, bridges);
        return bridges;
    }
};