class Solution {
    public int minDistance(String word1, String word2) {

        int len1 = word1.length();
        int len2 = word2.length();

        if (len1 == 0 || len2 == 0) {
            return len1 == 0 ? len2 : len1;
        }

        int dp[][] = new int[len1 + 1][len2 + 1];

        for (int i = 0; i <= len1; i++) {
            for (int j = 0; j <= len2; j++) {
                if (i == 0) {
                    dp[i][j] = j;
                } else if (j == 0) {
                    dp[i][j] = i;
                } else {
                    dp[i][j] = -1;
                }
            }
        }

        return getMidDistance(word1, word2, len1, len2, dp);
    }

    public int getMidDistance(String word1, String word2, int len1, int len2, int dp[][]) {

        if (len1 == 0) {
            return len2;
        }

        if (len2 == 0) {
            return len1;
        }

        if (dp[len1][len2] != -1) {
            return dp[len1][len2];
        }

        if (word1.charAt(len1 - 1) == word2.charAt(len2 - 1)) {
            return dp[len1][len2] = getMidDistance(word1, word2, len1 - 1, len2 - 1, dp);
        }

        int insertCharacter = getMidDistance(word1, word2, len1, len2 - 1, dp);
        int deleteCharacter = getMidDistance(word1, word2, len1 - 1, len2, dp);
        int replaceCharacter = getMidDistance(word1, word2, len1 - 1, len2 - 1, dp);

        return dp[len1][len2] = 1 + Math.min(insertCharacter, Math.min(deleteCharacter, replaceCharacter));
    }
}
