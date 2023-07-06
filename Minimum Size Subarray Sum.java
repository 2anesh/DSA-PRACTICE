class Solution {
    public int minSubArrayLen(int target, int[] nums) {
        int start = 0;
        int end =0;
        int min_len = Integer.MAX_VALUE;
        int sum=0;
        while(end<nums.length){
          
            if(nums[start]==target)
                return 1;
            
            sum+=nums[end];
            
            if(sum>=target){
                min_len=Math.min(min_len,end-start+1);
                
                //reset
                start++;
                end=start;
                sum=0;
                
            }else
                end++;
        }
        
        
        return (min_len!=Integer.MAX_VALUE)?min_len:0;
    }
}
