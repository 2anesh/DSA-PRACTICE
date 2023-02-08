class Solution {
public:
    int jump(vector<int>& nums) {
        int curr=0;
        int farthest=0;
        int jump=0;

        int n = nums.size();
        for(int i=0;i<n-1;i++)
         {
             farthest = max(farthest, nums[i]+i);

             if(i==curr)
              {
                  jump++;
                  curr= farthest;
              }
         }
       return jump;
    }
};
