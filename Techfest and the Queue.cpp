class Solution {
public:
    int sumOfPowers(int a, int b){
        // Code here
        int sum=0;
        for(int i=a;i<=b;i++)
        {
            int p=2;
            int j=i;
            while(sqrt(j)>=p)
            {
                if(j%p==0)
                {
                  sum++;
                  j/=p;
                }
                else p++;
            }
            if(i!=1)
            sum++;
        }
        return sum;
    }
};
