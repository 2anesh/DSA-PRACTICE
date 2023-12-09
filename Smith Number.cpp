class Solution {
  public:
    int smithNum(int &n) {
        
        int sum=0;
        int last;
        int temp=n;
        if(isPrime(n))
        {
            return 0;
        }
        else{
        for(;temp!=0;)
        {
            last=temp%10;
            sum=sum+last;
            temp=temp/10;
        }
        }
        if(sum==Primefactors(n))
        {
            return(1);
        }
    return(0);
}
        int Primefactors(int n)
        {
            int result=0;
            for(int i=2;i*i<=n;i++)
            {
                while(n%i==0)
                {
                    result=result+sumofdigits(i);
                    n=n/i;
                }
            }
            if(n>1)
            {
                result=result+sumofdigits(n);
            }
            return(result);
            
        }
        
         bool isPrime(int num) {
        if (num < 2) {
            return false;
        }
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }
    int sumofdigits(int n)
    {
       int sum=0;
       int temp=n;
       int last;
       for(;temp!=0;)
        {
            last=temp%10;
            sum=sum+last;
            temp=temp/10;
        }
        return(sum);
    }
};
