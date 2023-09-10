class Solution {
    public int countOrders(int n) {
        final long mod = 1000000007L;
        if(n==1)
        {
            return 1;
        }
        long res=1; 
        for(int i=2;i<=n;i++)
        {
            int space=(i-1)*2 + 1;
            long currentPossibility=space*(space+1)/2;
            res*=currentPossibility;
            res %= mod;
        }
        return (int) res;
    }
}
