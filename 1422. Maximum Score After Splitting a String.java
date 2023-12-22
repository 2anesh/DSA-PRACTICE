class Solution {
    public int maxScore(String s) {
        int maxScore = 0;
        int zeroesToLeft = 0, onesToRight = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '1') {
                onesToRight++;
            }
        }
        for (int i = 0; i < s.length() - 1; i++) {
            if (s.charAt(i) == '0') {
                zeroesToLeft++;
            } else {
                onesToRight--;
            }
            int currentScore = zeroesToLeft + onesToRight;
            maxScore = Math.max(maxScore, currentScore);
        }
     return maxScore;
    }
}
