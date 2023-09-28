class Solution {
    public int[] sortArrayByParity(int[] nums) {
        int count=0;
        for (int i=0;i<nums.length;i++)
        {
            
               if(nums[i]%2==0)
               {
                   count+=1;
                   int temp=nums[i];
                   nums[i]=nums[count-1];
                   nums[count-1]=temp;

               }
            
        }
        return nums;
    }
}
