class Solution {
public:
    set<vector<int>>ans;
    void dfs(vector<int>&nums,vector<int>v,int i){
        if(v.size()>=2){
            ans.insert(v);
        }
        if(i>=nums.size())
        {
            return ;
        }

        dfs(nums,v,i+1);

        if(v.size()==0){
            v.push_back(nums[i]);
        }
        else{
            if(v[v.size()-1]<=nums[i]){
                v.push_back(nums[i]);
            }
        }
        dfs(nums,v,i+1);
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int>v;
        vector<vector<int>>res;
     
         dfs(nums,v,0);
           for(auto x:ans){
            res.push_back(x);
        }
        return res;
    }
};
