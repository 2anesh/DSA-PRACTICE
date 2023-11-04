class Solution {
    public int getLastMoment(int n, int[] left, int[] right) {
        int lastFallTime = 0;
        
        // Determine the farthest position reached by ants moving to the left.
        for (int leftPosition : left) {
            lastFallTime = Math.max(lastFallTime, leftPosition);
        }
        
        // Determine the farthest position reached by ants moving to the right,
        // considering they start from the right end of the plank (n - position).
        for (int rightPosition : right) {
            lastFallTime = Math.max(lastFallTime, n - rightPosition);
        }
        
        return lastFallTime;
    }
}
