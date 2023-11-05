class Solution {
  public:
    vector<int> topK(vector<int>& nums, int k) {
        // Code here
        sort(nums.begin(),nums.end());
        vector<pair<int,int>> mp;
        int i=0;
        while(i<nums.size()){
            int j=0;
            while(nums[j+i]==nums[i] && i+j<nums.size()) j++;
            mp.push_back({j,nums[i]});
            i+=j;
        }
        sort(mp.begin(),mp.end());
        reverse(mp.begin(),mp.end());
        vector<int>ans;
        for(int i=0;i<k;i++) ans.push_back(mp[i].second);
        return ans;   
    }
};
