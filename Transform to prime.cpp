class Solution
{
    public:
    bool isprime(int num){
        if(num < 2) return false;
        for(int i = 2;i<=sqrt(num);i++){
            if(num % i == 0)
                return false;
        }
        return true;
    }
    int minNumber(int arr[],int N)
    {
        int sum = accumulate(arr,arr+N,0);
        if(isprime(sum))
            return 0;
        else{
            int ans = 0;
            for(int i = 1;;i++){
                sum++;
                if(isprime(sum)){
                    ans = i;
                    break;
                }
                    
            }
            return ans;
        }
        return 0;
    }
};
