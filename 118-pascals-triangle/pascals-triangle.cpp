class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        for(int i=0; i<numRows; i++){
            vector<int>temp(i+1, 1);
            int k=1; 
            while(k<temp.size()-1){
                temp[k]=ans[i-1][k-1] + ans[i-1][k];
                k++;
            }
            ans.push_back(temp);
        }
        return ans;
    }
};