class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
        [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
        int end=intervals[0][1];
        int start=intervals[0][0];
        vector<vector<int>>ans;
        for(int i =0; i<intervals.size()-1; i++){
            if(intervals[i+1][0]>end){
                ans.push_back({start, end});
                start=intervals[i+1][0];
                end=intervals[i+1][1];
            }else{
                end=max(end, intervals[i+1][1]);
            }
        }
        ans.push_back({start, end});
        return ans;
    }
};