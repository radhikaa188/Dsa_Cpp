class Solution {
public:
    class Disjoint{
        public:
        vector<int>rank, parent, size;
        
        //constructor
        Disjoint (int n){
            rank.resize(n+1, 0);
            parent.resize(n+1);
            size.resize(n+1, 1);
            for(int i=0; i<=n; i++){
                parent[i]=i;
            }
        }
        //ultimate_parent
        int findUParent(int node){
            if(parent[node]==node) return node;
            return parent[node]= findUParent(parent[node]);
        }
        void unionByRank(int u, int v){
            int ulp_u = findUParent(u);
            int ulp_v = findUParent(v);
            if(ulp_u == ulp_v) return;
            if(rank[ulp_u] > rank[ulp_v]){
                parent[ulp_v] = ulp_u;
            }else if(rank[ulp_v] > rank[ulp_u]){
                parent[ulp_u] = ulp_v;
            }else{
                parent[ulp_u] = ulp_v;
                rank[ulp_v]++;
            }
        }
        void unionBySize(int u, int v){
            int ulp_u = findUParent(u);
            int ulp_v = findUParent(v);
            if(ulp_u == ulp_v) return;
            if(size[ulp_u]>size[ulp_v]){
                parent[ulp_v]=ulp_u;
                size[ulp_u]+=size[ulp_v];
            }else{
                parent[ulp_u]=ulp_v;
                size[ulp_v]+=size[ulp_u];

            }
        }
    };

    int makeConnected(int n, vector<vector<int>>& connections) {
        Disjoint ds(n);
        int extraEdges=0;
        for(auto it : connections){
            int u=it[0];
            int v=it[1];
            if(ds.findUParent(u) == ds.findUParent(v)) extraEdges++;
            else{
                ds.unionBySize(u, v);
            }
        }
        int connectedComp=0;
        for(int i=0; i<n; i++){
            if(ds.parent[i]==i) connectedComp++;
        }
        if(extraEdges >= connectedComp-1) return connectedComp-1;
        else return -1;
    }
};