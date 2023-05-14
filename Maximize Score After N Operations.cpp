class Solution {
public:
    int dp[1<<15][8];
    int rec(int mask, int cnt, int n, vector<int> &arr){
        if(cnt==n+1){
            if(__builtin_popcount(mask) != 2*n) return -1e9;
            return 0;
        }
        if(dp[mask][cnt] != -1) return dp[mask][cnt];
        int ans = 0;
        for(int i=0; i<2*n; i++){
            for(int j=i+1; j<2*n; j++){
                if(!(mask&(1<<i)) && !(mask&(1<<j))){
                    int newmask = mask|(1<<i)|(1<<j);
                    ans = max(ans,rec(newmask,cnt+1,n,arr)+cnt*__gcd(arr[i],arr[j]));
                }
            }
        }
        return dp[mask][cnt]=ans;
    }
    int maxScore(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<(1<<n); i++){
            for(int j=0; j<=n/2; j++){
                dp[i][j]=-1;
            }
        }
        return rec(0,1,n/2,nums);
    }
};
