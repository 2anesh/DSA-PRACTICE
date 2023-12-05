class Solution {
    public static int numberOfMatches(int n) {
        int totalMatches = 0;
        while (n > 1) {
            totalMatches += n / 2;
            n = (n % 2 == 0) ? n / 2 : n / 2 + 1;
        }
        return totalMatches;
    }
}
