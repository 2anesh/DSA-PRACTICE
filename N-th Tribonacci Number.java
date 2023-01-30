class Solution {
    public int tribonacci(int n) {
        int t[]=new int[50];
        int i;
        t[0]=0;
        t[1]=1;
        t[2]=1;
        for(i=3;i<=n;i++)
        {
            int k;
            t[i]=t[i-3]+t[i-2]+t[i-1];
        }
        return t[n];
    }
}
