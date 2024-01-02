class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>>ans;
        unordered_map<int, int>mp;
        for(auto i:nums)
            mp[i]++;
        while(true)
        {
            vector<int>v;
            for(auto [key,value]:mp)
            {
                if(value)
                {
                    v.push_back(key);
                    mp[key]--;
                }
            }
            if(!v.size())
                break;
            ans.push_back(v);
        }
        return ans;
    }
};
