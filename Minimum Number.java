class Solution {
    public static int minimumNumber(int n, int[] arr) {
        // code here
        int i=0,res=0;
        for(i=0;i<n;i++)
        {
            res=gcd(res,arr[i]);
        }
        return res;
    }
    public static int gcd(int a,int b)
    {
        if(b==0)
        return a;
        else
        return gcd(b,a%b);
    }
}
