class Solution {
	public:
	int mod=1e9+7;
	vector<int>dp;
	bool valid(int n){
	    return (n>=1&&n<=26);
	}
	int solve(int i,int n,string &s){
	    if(i==n)return 1;
	    if(i>n)return 0;
	    if(dp[i]!=-1)return dp[i]%mod;
	        int choice1=0;
	   
	        int choice2=0;
	        if(s[i]!='0'){
	        if(valid(s[i]-'0'))choice1=solve(i+1,n,s)%mod;
	        if(i<n-1){
	            int num=10*(s[i]-'0')+(s[i+1]-'0');
	            if(valid(num))choice2=solve(i+2,n,s)%mod;
	        }
	        }
	 return dp[i]=(choice1%mod+choice2%mod)%mod;
	   
	}
		int CountWays(string s){
		    int n=s.length();
		    dp=vector<int>(n+1,-1);
		    return solve(0,n,s);
		}
};
