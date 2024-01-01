class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
         int num=nums.size();
         if(num%2) return false;
         unordered_map<int,int>mp;
         for(int i=0;i<num;i++){
             mp[nums[i]%k]++;
         }
         for(auto it:mp){
             int p=it.first;
             int q=it.second;
             int req=k-p;
             if(p==0 and mp[p]%2==0) continue;
             if(mp[req]!=q) return 0;             
         }
         return 1;
    }
};
