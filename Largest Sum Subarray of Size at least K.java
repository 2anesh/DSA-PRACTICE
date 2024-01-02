class Solution {
    
    public long maxSumWithK(long a[], long n, long k)
    {
          long add = 0, sum1 = 0, sub = 0, sum2 = 0;
        long i = 0;

        while (i < k)
            sum1 += a[(int) i++];

        add = sum1;

        while (i < n) {
            sum1 += a[(int) i];
            sum2 += a[(int) (i - k)];
            sub = Math.min(sub, sum2);
            add = Math.max(add, sum1 - sub);
            ++i;
        }

        return add;
        
    }
}
