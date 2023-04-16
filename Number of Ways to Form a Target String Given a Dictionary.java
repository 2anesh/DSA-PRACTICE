class Solution {
    private static final int MOD = 1000000007;

    public int numWays(String[] words, String target) {
        int k = words[0].length();
        int m = target.length();
        int[][] cnt = new int[k][26];

        for (int i = 0; i < k; i++) {
            for (String word : words) {
                cnt[i][word.charAt(i) - 'a']++;
            }
        }

        Map<String, Integer> memo = new HashMap<>();
        return (int) dfs(0, 0, m, cnt, target, memo);
    }

    private long dfs(int i, int t, int m, int[][] cnt, String target, Map<String, Integer> memo) {
        if (t == m) {
            return 1;
        }
        if (i >= cnt.length) {
            return 0;
        }

        String key = i + "_" + t;
        if (memo.containsKey(key)) {
            return memo.get(key);
        }

        long res = 0;
        if (cnt[i][target.charAt(t) - 'a'] > 0) {
            res += cnt[i][target.charAt(t) - 'a'] * dfs(i + 1, t + 1, m, cnt, target, memo);
        }
        res += dfs(i + 1, t, m, cnt, target, memo);

        res %= MOD;
        memo.put(key, (int) res);
        return res;
    }
}
