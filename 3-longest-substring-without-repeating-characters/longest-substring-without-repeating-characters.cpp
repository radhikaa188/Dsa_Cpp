class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int>mpp;
        int n = s.size();
        int cnt=0;
        int res=0;
        int left=0;
        for(int i=0; i<n; i++){
            mpp[s[i]]++;
            while(mpp[s[i]]>1){
                mpp[s[left]]--;
                left++;
            }
            res=max(res,i-left+1);
        }
    return res;
    }
};