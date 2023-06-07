class Solution{
    static boolean isPrime(int n){
        for(int i=2;i<=Math.sqrt(n);i++){
            if(n%i==0)return false;
        }
        return true;
    }
    public int[] leastPrimeFactor(int n){
        int ret[]=new int[n+1];
        ret[0]=0;
        ret[1]=1;
        for(int i=2;i<=n;i++){
            for(int j=2;j<=i;j++){
                if(i%j==0 && isPrime(j)){
                    ret[i]=j;
                    break;
                }
            }
        }
        return ret;
    }
}
