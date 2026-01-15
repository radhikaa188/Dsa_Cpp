class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
     vector<int>sumArr(nums.size(), 0);
     int sum=0;
     int count=0;
     for(int i=0; i<nums.size(); i++){
        sum+=nums[i];
        sumArr[i]=sum;
     }
     for(int j=0; j<nums.size();j++){
         unordered_set<int> st;
        for(int k=j; k<nums.size(); k++){
            int subSum = sumArr[k] - (j > 0 ? sumArr[j-1] : 0);
            st.insert(nums[k]);
            if (st.find(subSum) != st.end()) {
                count++;
            }

        }
     }
        return count;
     }
};