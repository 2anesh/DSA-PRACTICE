class Solution {
    public int singleNonDuplicate(int[] nums) {
        int uni=Integer.MIN_VALUE;
        int n=nums.length;
        if(n==1){
            return nums[0];
        }
        for(int i=0;i<n;i++){
            if(i==n-1){
                uni=nums[i];
                break;
            }
            if(nums[i]==nums[i+1]){
                i++;
            }else{
                uni=nums[i];
                break;
            }
        }
        return uni;

    }
}
