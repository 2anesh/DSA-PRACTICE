class Solution {
public boolean validPartition(int[] nums) {
return solve(nums,0,new Boolean[nums.length]);// new Boolean[nums.length] indicates dynamic array }
}
public boolean solve(int[] nums,int i,Boolean[] dp)
{
// if array out of bound condition
if(i==nums.length)
return true;
// memotization
if(dp[i]!=null)
return dp[i];

    Boolean result=false;
    //The subarray consists of exactly 2 equal elements. 
    if((i+1)<nums.length && (nums[i]==nums[i+1])) {
         result  |= solve(nums,i+2,dp);
    }
    //  The subarray consists of exactly 3 equal elements.  
    if((i+2)<nums.length && (nums[i] == nums[i+1]) && (nums[i+1]==nums[i+2])){
              result |= solve(nums,i+3,dp);
    }
      //  The subarray consists of exactly 3 consecutive increasing elements, that is, the difference between adjacent elements is 1.                     
    if((i+2) <nums.length && nums[i]+1 == nums[i+1] && nums[i]+2 == nums[i+2]){
             result |= solve(nums,i+3,dp);
    }
         return dp[i]=result; 
    }
}
