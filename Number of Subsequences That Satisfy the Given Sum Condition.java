class Solution {
    public int numSubseq(int[] nums, int target) {
        Arrays.sort(nums); // Sort the array in non-decreasing order
        int n = nums.length;
        int mod = 1000000007;
        int left = 0, right = n - 1;
        long ans = 0;
        int[] pow2 = new int[n];
        pow2[0] = 1;
        for (int i = 1; i < n; i++) {
            pow2[i] = (pow2[i - 1] * 2) % mod; // Precompute powers of 2
        }
        while (left <= right) { // Two pointer approach to count subsequences
            if (nums[left] + nums[right] > target) {
                right--; // If sum of min and max is greater than target, decrement right
            } else {
                ans = (ans + pow2[right - left]) % mod; // Compute number of subsequences using precomputed powers of 2
                left++; // Increment left
            }
        }
        return (int) ans; // Return answer modulo 10^9+7
    }
}
