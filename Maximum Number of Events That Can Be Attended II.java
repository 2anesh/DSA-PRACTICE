class Solution {
    public int maxValue(int[][] events, int k) {
         Arrays.sort(events, (a, b) -> a[1] - b[1]);
        int n = events.length;
        int[][] dp = new int[k+1][n+1];

        for (int i = 1; i <= k; i++) {
            for (int j = 1; j <= n; j++) {
                int prev = findPreviousEvent(events, j);
                dp[i][j] = Math.max(dp[i][j-1], dp[i-1][prev] + events[j-1][2]);
            }
        }

        return dp[k][n];
    }

    private int findPreviousEvent(int[][] events, int current) {
        int start = events[current-1][0];
        int low = 0, high = current - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (events[mid][1] < start)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return low;
    }
}
