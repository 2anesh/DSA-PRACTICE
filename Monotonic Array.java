
class Solution {
    public boolean isMonotonic(int[] nums) {
        boolean inc = true; // Flag to track monotone increasing
        boolean dec = true; // Flag to track monotone decreasing
        
        for (int i = 0; i < nums.length - 1; i++) {
            if (nums[i] > nums[i + 1])
                inc = false; // If current element is greater than the next element, it's not monotone increasing
            if (nums[i] < nums[i + 1])
                dec = false; // If current element is smaller than the next element, it's not monotone decreasing
        }
        
        return inc || dec; // Return true if either inc or dec is true, indicating the array is monotonic
    }
}
