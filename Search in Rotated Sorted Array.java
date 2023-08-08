class Solution {
    public static int binarySearch(int nums[],int start,int end,int target){
        while(start<=end){
            int mid = start+(end-start)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if (nums[mid]>target){
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return -1;
    }
    public static int splt(int nums[]){
        int start = 0,mid = 0,end = nums.length-1;
        while(start<end){
            mid = start+(end-start)/2;
            if(nums[mid]>nums[mid+1]){
                return mid+1;
            }
            else if(nums[mid]<nums[start]){
                end = mid;
            }
            else{
                start = mid+1;
            }
        }
        return 0;
    }
    public int search(int[] nums, int target) {
        int start = 0,mid = 0,end = nums.length-1;
        if(nums[start]<nums[end]){
            return binarySearch(nums,start,end,target);
        }
        else{
            int spl = splt(nums);
            int res = binarySearch(nums,start,spl,target);
            if(res!=-1){
                return res;
            }
            return binarySearch(nums,spl,nums.length-1,target);
        }
    }
}
