class Solution {
public:
    #define ll long long
    ll mod = 1e9+7;
    bool check(vector<string>& pizza,int up,int lo,int le,int ri){
        for(int i = up; i <= lo; i++){
            for(int j = le; j <= ri; j++){
                if(pizza[i][j] == 'A'){
                    return true;
                }
            }
        }
        return false;
    }
    ll cuts(int sh,int eh,int sv,int ev,vector<string>& pizza,int k,vector<vector<vector<ll>>>& dp){
        if(k == 0){
            return 1LL;
        }
        if(dp[sh][sv][k] != -1){
            return dp[sh][sv][k];
        }
        ll ans = 0;
        // Make Horizonatal Cuts First
        for(int i = sh; i < eh; i++){
            if(check(pizza,sh,i,sv,ev) && check(pizza,i+1,eh,sv,ev)){
                ans += cuts(i+1,eh,sv,ev,pizza,k-1,dp);
            }
        }
        // Make Vertical Cuts
        for(int j = sv; j < ev; j++){
            if(check(pizza,sh,eh,sv,j) && check(pizza,sh,eh,j+1,ev)){
                ans += cuts(sh,eh,j+1,ev,pizza,k-1,dp);
            }
        }
        return dp[sh][sv][k] = ans % mod;
    }
    int ways(vector<string>& pizza, int k) {
        ios_base::sync_with_stdio(0);
        int n = pizza.size(),m = pizza[0].size();
        vector<vector<vector<ll>>>dp(n,vector<vector<ll>>(m,vector<ll>(k,-1)));
        return cuts(0,n-1,0,m-1,pizza,k-1,dp);
    }
};
