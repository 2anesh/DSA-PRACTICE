class Solution{
public:
    int mod = 1000000007;
    long long int power(long long int x, long long int y, long long int p)
    {
        long long int res = 1;
        while (y > 0) {
            if (y % 2 == 1)
                res = (res *1ll* x)%p;
            y = y >> 1;
            x = (x *1ll* x)%p;
        }
        return res % p;
    }
    int f(vector<int> &arr,int ind,long long mul,vector<int> factors[],vector<unordered_map<long long,long long>> &dp)
    {
        if(ind==0) return 1;
        if(dp[ind].find(mul)!=dp[ind].end()) return dp[ind][mul];
        int ways =f(arr,ind-1,mul,factors,dp)%mod;
        if(arr[ind]!=0)
        {
            bool flag = true;
            for(auto &it:factors[ind]) if(mul%it==0) flag = false;
            if(flag) ways = (ways+(arr[ind]*1ll*f(arr,ind-1,mul*1ll*ind,factors,dp))%mod)%mod;
        }
        return dp[ind][mul]=ways;
    }
    int goodSubsets(vector<int> &arr, int n){
        // Code here
        int ones =0;
        vector<int> sec(31,0);
        vector<int> primes = {2,3,5,7,11,13,17,19,23,29};
        vector<int> factors[31];
        for(int i =2;i<=30;i++)
        {
            if(((i%4)==0)||((i%9)==0)||((i%16)==0)||((i%25)==0)) 
            {
                factors[i].push_back(0);
                continue;
            }
            else{
                int num = i;
                for(int j=0;j<10;j++)
                {
                    if(num%primes[j]==0) {
                        factors[i].push_back(primes[j]);
                        num = num/primes[j];
                        if(num==0) break;
                    }
                }
                    
            }
        }
        for(auto &i:arr) 
        {
            if(((i%4)==0)||((i%9)==0)||((i%16)==0)||((i%25)==0)||(i==1&&++ones)) sec[i]=0;
            else sec[i]++;
        }
        vector<unordered_map<long long,long long>> dp(sec.size()+1);
        long long ans = f(sec,30,1,factors,dp);
        ans = ans-1;
        ans = (ans*1ll*power(2,ones,mod))%mod;
        return ans;
    }
