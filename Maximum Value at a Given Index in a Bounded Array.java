class Solution {
    public int maxValue(int arrayLength, int targetIndex, int maxSum) {
        int left = 0;
        int right = maxSum - arrayLength;

        while (left < right) {
            int mid = (left + right + 1) / 2;
            if (isPossible(arrayLength, targetIndex, maxSum - arrayLength, mid))
                left = mid;
            else
                right = mid - 1;
        }
        return left + 1;
    }

    public boolean isPossible(int arrayLength, int targetIndex, int maxSum, int value) {
        int leftVal = Math.max(value - targetIndex, 0);
        int rightVal = Math.max(value - ((arrayLength - 1) - targetIndex), 0);

        long sumBefore = (long) (value + leftVal) * (value - leftVal + 1) / 2;
        long sumAfter = (long) (value + rightVal) * (value - rightVal + 1) / 2;

        return sumBefore + sumAfter - value <= maxSum;
    }
}
