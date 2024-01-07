class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {     
        vector<unordered_map<long long int,long long int>>dp(nums.size());
        long long int answer=0;       
        for(int i=1;i<nums.size();i++)
        {
            long long int currele=nums[i];
            for(int j=i-1;j>=0;j--)
            {
                long long int diff=currele-nums[j]; 
                
                if(dp[j].find(diff)==dp[j].end())
                {
                    answer+=0;
                    dp[i][diff]=dp[i][diff]+1;
                }
                else
                {
                    answer+=dp[j][diff];
                    dp[i][diff]=dp[i][diff]+1+dp[j][diff];
                }
            }
        }
        return answer;
    }
};
