class Solution {
    public static long sum(long n) {
        long c=0;
        while(n%2==0) {
            c++;
            n/=2;
        }
        for(int i=3; i<=(int)Math.sqrt(n); i+=2) {
            while(n%i==0) {
                c++;
                n/=i;
            }
        }
        if(n>2) c++;
        return c;
    }
    public static long sumOfPowers(long a, long b) {
        // code here
        long ans = 0;
        for(long i=a; i<=b; i++) {
            ans += sum(i);
        }
        return ans;
    }
}

