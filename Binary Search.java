class Solution
{
public int search(int[] nums, int target)
{
int n = nums.length;
int l = 0, r = n - 1, mid;
while(l <= r){
mid = (l + r) / 2;
if(nums[mid] > target)
r = mid - 1;
if(nums[mid] < target)
l = mid + 1;
if(nums[mid] == target)
return mid;
}
return -1;
}
}
