class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        //dijkstra's algo for each node 
        //adjList
        vector<vector<pair<int,int>>>adjList(n);
        for(auto i: edges){
            adjList[i[0]].push_back({i[1], i[2]});
            adjList[i[1]].push_back({i[0], i[2]});
        }
        vector<vector<int>>dist(n, vector<int>(n, 1e9));
        for(int src=0; src<n; src++){
            //set
            set<pair<int,int>> st;
            dist[src][src]=0;
            st.insert({0, src});
            while(!st.empty()){
                auto it = st.begin();
                int wt=it->first;
                int node=it->second;
                st.erase(it);
                for(auto edge: adjList[node]){
                    int distance= edge.second;
                    int adjNode= edge.first;
                    if(distance + wt < dist[src][adjNode]){
                        dist[src][adjNode] = distance + wt;
                        st.insert({dist[src][adjNode], adjNode});
                    }
                }
            }
        }
        int result = INT_MAX;
        int city = -1;
        for(int i=0; i<n; i++){
            int count=0;
            for(int j=0; j<n; j++){
                if( i!=j && dist[i][j]<=distanceThreshold){
                    count++;
                }
            }
            if(count <= result){
                result=count;
                city = i;
            }
        }
        return city;
    }
};