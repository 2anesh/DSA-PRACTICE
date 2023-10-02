class Solution{
public:	
    #define ll long long
    const ll mod=1e9+7;
	int distinctSubsequences(string s) {
	    int n=s.size();
	    vector<ll> pos(26,n);
	    vector<ll> dp(n+1,0);
	    ll ans=1;
	    for(int i=n-1;i>=0;i--){
	        ll cur = dp[i+1];
	        if(pos[s[i]-'a'] < n)
	            cur=(cur-dp[pos[s[i]-'a']+1]+mod)%mod;
	        else
	            cur=(cur+1)%mod;
	        dp[i]=(cur+dp[i+1])%mod;
	        pos[s[i]-'a']=i;
	    }
	    return dp[0]+1;
	}
};
