class Solution {
  public static int buyChoco(int[] prices, int money) {
    int minPrice = Integer.MAX_VALUE;
    int secMinPrice = Integer.MAX_VALUE;
    for (int item : prices) {
      if (item < minPrice) {
        secMinPrice = minPrice;
        minPrice = item;
      } else if (item < secMinPrice) {
        secMinPrice = item;
      }
    }
    if (money - minPrice - secMinPrice >= 0) {
      return money - minPrice - secMinPrice;
    } else {
      return money;
    }
  }
}
