class Solution {
    public long countSubarrays(int[] nums, int minK, int maxK) {
         long result = 0;

        int min = -1;
        int max = -1;
        int bad = 0;

        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == minK) {
                min = i;
            } else if (nums[i] < minK) {
                min = -1;
                max = -1;
                bad = i+1;
            }
            if (nums[i] == maxK) {
                max = i;
            } else if (nums[i] > maxK) {
                max = -1;
                min = -1;
                bad = i+1;
            }

            if (min >= 0 && max >= 0) {
                result += Math.min(max, min) - bad + 1;
            }

        }
        return result;
    }
}
