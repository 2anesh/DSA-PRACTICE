class Solution {
  public:
     int isPerfectNumber(long long N) {
        // code here
        long long sum = 0;
        long long n = N;
        long long t = N;
        for(int i = 1; i < sqrt(N); i++)
        {
            if(N % i == 0)
            {
                sum += i;
                if(t / i != n)
                    sum += t / i;
            }
        }
        if(sum == n)
            return 1;
        else
            return 0;
    }
};
