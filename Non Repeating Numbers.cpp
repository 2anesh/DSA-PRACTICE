class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        // Code here.
        map<int, int> mp;
        vector<int> v;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        
        for(auto it: mp){
            if(it.second == 1){
                v.push_back(it.first);
            }
        }
        return v;
    }

};
