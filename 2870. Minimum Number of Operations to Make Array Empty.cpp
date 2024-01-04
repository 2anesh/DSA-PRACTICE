class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> mapping;
        for(int i=0;i<nums.size();i++){
            mapping[nums[i]]++;
        }
        int t_count=0;
        for(auto i:mapping){
            if(i.second==1){
                return -1;
            }
            t_count+=ceil((double)i.second/3);
        }
        return t_count;
    }
};
