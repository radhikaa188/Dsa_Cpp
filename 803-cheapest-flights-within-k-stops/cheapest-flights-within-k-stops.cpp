class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>>adj[n];
        for(auto it: flights){
            adj[it[0]].push_back({it[1], it[2]});
        }
        queue<pair<int,pair<int, int>>>q;
        vector<int>distance(n, 1e9);
        //stops,node,dis
        q.push({0,{src,0}});
        distance[src]=0;

        while(!q.empty()){
            auto itr=q.front();
            q.pop();
            int stops = itr.first;
            int node = itr.second.first;
            int path = itr.second.second;
            if(stops > k+1) continue;
            for(auto m: adj[node]){
                int adjNode=m.first;
                int cost=m.second;
                if(distance[adjNode] > path+ cost && stops<=k){
                    distance[adjNode] = path+ cost;
                    q.push({stops+1,{adjNode, distance[adjNode]}});
                }
            }
        }

        if(distance[dst]==1e9) return -1;
        return distance[dst];
    }
};