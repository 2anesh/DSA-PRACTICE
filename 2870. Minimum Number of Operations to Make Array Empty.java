class Solution {
    public int minOperations(int[] nums) {
      int result = 0;
      Map<Integer, Integer> count = new HashMap<>();
      for(final int num: nums)
      count.merge(num,1,Integer::sum);
      for(final int freq : count.values()){
           if(freq == 1)
           return -1;
           result  += (freq +2) /3;
      }
        return result;
    }
}
