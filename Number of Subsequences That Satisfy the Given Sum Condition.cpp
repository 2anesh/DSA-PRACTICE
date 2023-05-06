class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        int mod = 1e9+7;

        sort(nums.begin(),nums.end());
        int ans = 0,l=0,r=n-1;

        vector<int> power(n, 1);
        for (int i = 1; i < n; i++) {
            power[i] = (power[i - 1] * 2) % mod;
        }

        while(l<=r){
            if(nums[l]+nums[r]<=target){
                ans = (ans + power[r-l])%mod;
                l++;
            }
            else{
                r--;
            }
        }
        return ans;
    }
};
