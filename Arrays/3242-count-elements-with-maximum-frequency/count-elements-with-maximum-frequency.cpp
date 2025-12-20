class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        // map to store the frreq of ele
        unordered_map<int, int> mp;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        //finding maxFreq
        int maxFreq=0;
        for(auto &p: mp){
            maxFreq= max(maxFreq, p.second);
        }
        // number of ele with maxFreq
        int count=0;
        for(auto &p:mp){
            if(p.second == maxFreq) count++;
        }
        return maxFreq*count;
    }
};