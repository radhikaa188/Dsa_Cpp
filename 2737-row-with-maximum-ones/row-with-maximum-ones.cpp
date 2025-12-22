class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int ones=0;
        int idx=0;
        vector<int>res;
        for(int i=0; i<mat.size(); i++){
            int count=0;
            for(int j=0; j<mat[0].size(); j++){
                if(mat[i][j]==1){
                count++;
                if(count>ones){
                    idx=i;
                    ones=count;
                }
                }
            }
        }
        res.push_back(idx);
        res.push_back(ones);
        return res;
    }
};