class Solution
{
     public long findNumber(long N)
    {
        long[] v = { 9, 1, 3, 5, 7 };
        long ans = 0;
        while (N > 0) {
          ans = ans * 10 + v[(int)(N % 5)];
          if (N % 5 == 0) {
            N = N / 5;
            N--;
          }
          else
            N /= 5;
        }
        Queue<Long> q = new ArrayDeque<>();
        while (ans > 0) {
          q.add(ans % 10);
          ans /= 10;
        }
        while (!q.isEmpty()) {
          ans = ans * 10 + q.peek();
          q.remove();
        }
        return ans;
    }
}
