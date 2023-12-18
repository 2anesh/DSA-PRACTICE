class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int ma=nums[0]*nums[1];
        int me=nums[n-1]*nums[n-2];
        int ans=me-ma;
        return ans;
        
    }
};
