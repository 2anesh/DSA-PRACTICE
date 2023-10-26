class Solution
{
  public:
    int minOperation(int n)
    {
        //code here.
        int a=-1,b=-1;
        while(n){
            a++;
            if(n&1) b++;
            n>>=1;
        }
        return 1+a+b;
    }
};
