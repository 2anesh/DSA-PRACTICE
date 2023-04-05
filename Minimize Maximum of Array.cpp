class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        long long max_min_val = 0; // maximum minimum value
        long long cur_sum = 0; // current sum
        for(int i=0;i<nums.size();i++){
            cur_sum += nums[i];
            long long cur_min_val = ceil((cur_sum)/(i+1.0)); // current minimum value
            max_min_val = max(max_min_val, cur_min_val); // update maximum minimum value
        }
        return max_min_val;
    }
};
