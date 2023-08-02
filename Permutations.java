class Solution {
    public void helper(List<Integer> ls ,boolean[] arr, List<List<Integer>> res, int[] nums){
        if(ls.size() == nums.length){
            res.add(new ArrayList<>(ls));
            return;
        }

        for(int i = 0; i<nums.length; i++){
            if(!arr[i]){
                arr[i] = true;
                ls.add(nums[i]);
                helper(ls, arr, res, nums);
                arr[i] = false;
                ls.remove(ls.size()-1);
            }
        }
    }
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        helper(new ArrayList<>(), new boolean[nums.length], res, nums);   
        return res;     
    }
}
