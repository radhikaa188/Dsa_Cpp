class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i=0;
        int j=0;
        vector<int>result;
        while(i < nums1.size() && j < nums2.size()){
            if(nums1[i]!=nums2[j]){
                if(nums1[i]<nums2[j]) i++;
                else j++;
            }else{
                if(result.empty() || nums1[i]!=result[result.size()-1]){
                result.push_back(nums1[i]);
                }
                    i++;
                    j++;
            }
        }
        return result;
    }
};