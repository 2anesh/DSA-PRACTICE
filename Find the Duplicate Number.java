 class Solution {
    public int findDuplicate(int[] nums) {
        //using cyclic sort
        
        int i=0;
        while(i < nums.length)
        {
            int correct_index = nums[i] - 1;
            
            if(nums[i] != nums[correct_index])
            {
                swap(nums, i, correct_index);
            }
            else
                i++;
        }
        
        // finding the duplicate element
        int ans=0;
        for(int index=0; index<nums.length; index++)
        {
            if(nums[index] != index+1)
                ans = nums[index];
        }
        
        return ans;
     
  }
    void swap(int[] arr, int first, int second)
    {
        int temp = arr[first];
        arr[first] = arr[second];
        arr[second] = temp;
    }
}
