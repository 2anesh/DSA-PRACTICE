class Solution {
    public static long findMaxSubsetSum(int N, int[] A) {
        long prev0 = 0;
        long prev1 = A[0];

        for (int i = 1; i < N; i++) {
            long cur1 = A[i] + Math.max(prev0, prev1);
            long cur0 = prev1;

            prev0 = cur0;
            prev1 = cur1;
        }

        return Math.max(prev0, prev1);
    }
}

