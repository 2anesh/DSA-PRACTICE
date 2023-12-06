class Solution {
    public int totalMoney(int n) {
        int total = 0;
        int weekNumber = 1;

        for (int i = 0; i < n; i++) {
            total += weekNumber + i % 7;
            if ((i + 1) % 7 == 0) {
                weekNumber++;
            }
        }
        return total;
    }
}
