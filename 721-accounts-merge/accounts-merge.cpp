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

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        Disjoint ds(n);
        unordered_map<string, int>mailList;
        for(int i=0; i<n; i++){
            for(int j=1; j<accounts[i].size(); j++){
                if(mailList.find(accounts[i][j]) == mailList.end()){
                    mailList[accounts[i][j]] = i;
                }else{
                    ds.unionBySize(mailList[accounts[i][j]], i);
                }
            }
        }
        vector<vector<string>>mergeMail(n);
        for(auto it: mailList){
            string mail = it.first;
            int node = ds.findUParent(it.second);
            mergeMail[node].push_back(mail);
        }
        vector<vector<string>>ans;
        for(int i=0; i<n; i++){
            if(mergeMail[i].size() == 0) continue;
            sort(mergeMail[i].begin(), mergeMail[i].end());
            vector<string>temp;
            temp.push_back(accounts[i][0]);
            for(auto k: mergeMail[i]){
                temp.push_back(k);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};