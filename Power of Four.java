class Solution {
    public boolean isPowerOfFour(int n) {
        double a = n;
        while (a > 2) {
            a = a / 4;
        }
        if (a == 1.0) {
            return true;
        }
        return false;
    }
}
