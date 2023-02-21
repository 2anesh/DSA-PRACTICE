class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int ans=0;
        int i=0;
        if(nums.size()==1)
        {
            return nums[0];
        }
        while(i<nums.size()-1)
        {
            if(nums[i]!=nums[i+1])
            {
                ans=nums[i];
                break;
            }
            else
            {
                i+=2;
            }
        }
        if(ans==0)
        {
            if(nums[nums.size()-1]!=nums[nums.size()-2] && nums[nums.size()-3]==nums[nums.size()-2] )
            {
                ans = nums[nums.size()-1];
            }
        }
        return ans;
        
    }
};
