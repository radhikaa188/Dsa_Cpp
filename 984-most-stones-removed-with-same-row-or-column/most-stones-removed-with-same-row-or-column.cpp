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

    int removeStones(vector<vector<int>>& stones) {
        int maxRow=0;
        int maxCol=0;
        for(auto it: stones){
            maxRow= max(maxRow, it[0]);
            maxCol= max(maxCol, it[1]);
        }
        Disjoint ds(maxRow+maxCol+1);
        unordered_map<int, int> stonesNodes;
        for(auto i: stones){
            int row = i[0];
            int col = i[1]+maxRow+1;
            ds.unionBySize(row, col);
            stonesNodes[row]=1;
            stonesNodes[col]=1;
        }
        int count=0;
        for(auto k: stonesNodes){
            if(ds.findUParent(k.first)==k.first){
                count++;
            }
        }
        return stones.size()-count;
    }
};