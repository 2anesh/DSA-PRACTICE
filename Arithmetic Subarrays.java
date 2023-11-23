class Solution {
    public List<Boolean> checkArithmeticSubarrays(int[] nums, int[] l, int[] r) {

       List<Boolean> result = new ArrayList<>();
       for(int i = 0; i<l.length ; i++){
           result.add(check(nums,l[i] , r[i]));
       }
       return result;
    }

    public boolean check(int[] nums , int l1 , int  r1){

        int[] ans = new int[r1-l1+1];
        int index=0;
        for(int i = l1 ; i <= r1 ; i ++){
            ans[index++] = nums[i];
        }

        Arrays.sort(ans);

        int d = ans[1] - ans[0];
        for(int i = 1; i < ans.length - 1; i++){
            if(ans[i+1] - ans[i] != d){
                return false;
            }
        }

        return true;

    }
} 
