class Solution {
public:
    int mod = 1e9 + 7;

    int solve(int n, int target, int k, std::vector<std::vector<int>> &memo) {
        if (target == 0 && n == 0) return 1;
        if (n == 0 || target < 0) return 0;

        if (memo[n][target] != -1) {
            return memo[n][target];
        }

        int ways = 0;
        for (int i = 1; i <= k; i++) {
            if (i <= target) {
                ways = (ways % mod + solve(n - 1, target - i, k, memo) % mod) % mod;
            }
        }

        memo[n][target] = ways;
        return ways;
    }

    int numRollsToTarget(int n, int k, int target) {
        // Initialize memoization table with -1
        std::vector<std::vector<int>> memo(n + 1, std::vector<int>(target + 1, -1));

        return solve(n, target, k, memo);
    }
};
