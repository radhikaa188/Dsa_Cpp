class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProd= nums[0];
        int minProd= nums[0];
        int ans= nums[0];
        // we will keep the track of min and max product 
        for(int i=1; i<nums.size(); i++){
            //i the --ve ele comes up we will swap
            if(nums[i]<0) swap(maxProd, minProd);
            maxProd= max(maxProd*nums[i], nums[i]);
            minProd= min(minProd*nums[i], nums[i]);
            ans= max(ans, maxProd);
        }
        return ans;
    }
};