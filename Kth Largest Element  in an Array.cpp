class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        // Code here.
          vector<int>vec;
        map<int,int>mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        for(auto it:mpp){
            if(it.second == 1)vec.push_back(it.first);
        }
        return vec;
    }
};
