class Solution
{
public:
    long long sumOfDivisors(int N)
    {  long long res=N;
       for(int i=2;i<=N;i++){
                res=res+((N/i)*i);
         }
    return res;
    }
};
