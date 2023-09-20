class Solution {
public int minOperations(int[] nums, int x) {
int sum =0;
for(int num : nums){
sum += num;
}
int k= sum -x;
int left =0;
int windowSum =0;
int globalMax =-1;
for(int i=0; i< nums.length;i++){
//Work TBD to solve the subproblem ending at index i
windowSum += nums[i];
while(left <=i && windowSum > k){
windowSum -= nums[left];
left++;
}
if(windowSum == k){
globalMax = Math.max(globalMax, i-left+1);
}
}
return globalMax ==-1 ? -1 : nums.length - globalMax;
}
}
