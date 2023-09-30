class Solution {
    public boolean find132pattern(int[] nums) {
        int n = nums.length;
        if (n < 3) {
            return false;
        }

        int[] minSoFar = new int[n];
        minSoFar[0] = nums[0];

        // Calculate the minimum value for each position in the array
        for (int i = 1; i < n; i++) {
            minSoFar[i] = Math.min(minSoFar[i - 1], nums[i]);
        }

        Stack<Integer> stack = new Stack<>();
        
        for (int j = n - 1; j >= 0; j--) {
            if (nums[j] > minSoFar[j]) {
                while (!stack.isEmpty() && stack.peek() <= minSoFar[j]) {
                    stack.pop();
                }
                
                if (!stack.isEmpty() && stack.peek() < nums[j]) {
                    return true;
                }
                stack.push(nums[j]);
            }
        }

        return false;
    }
}
