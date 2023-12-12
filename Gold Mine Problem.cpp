class Solution{
public:
    int solve(vector <vector<int>> &dp,int i, int j,vector <vector<int>> &M,int n,int m){
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int up_right=0,right=0,down_right=0;
        if(j<m-1 && i>0 && i<n-1){
            up_right = solve(dp,i-1,j+1,M,n,m);
            right = solve(dp,i,j+1,M,n,m);
            down_right = solve(dp,i+1,j+1,M,n,m);
            int maxi = max(up_right,right);
            dp[i][j]=max(maxi,down_right)+M[i][j];
        }
        if(j<m-1 && i==0){
            right = solve(dp,i,j+1,M,n,m);
            down_right = solve(dp,i+1,j+1,M,n,m);
            dp[i][j]=max(right,down_right)+M[i][j];
        }
        if(j<m-1 && i==n-1){
            up_right = solve(dp,i-1,j+1,M,n,m);
            right = solve(dp,i,j+1,M,n,m);
            dp[i][j]=max(right,up_right)+M[i][j];
        }
        
        
        return dp[i][j];
        
    }
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        // code here
        if(n==1){
            int ans=0;
            for(int i=0;i<m;i++){
                ans+=M[0][i];
            }
            return ans;
        }
        if(m==1){
            int ans = 0;
            for(int i=0;i<n;i++){
                ans=max(M[i][0],ans);
            }
            return ans;
        }
        vector <vector<int>> dp(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            dp[i][m-1]=M[i][m-1];
        }
        
        
        int maxi = 0;
        for(int i=0;i<n;i++){
            int a = solve(dp,i,0,M,n, m);
            maxi = max(a,maxi);
        }
        
        
        return maxi;
        
    }
};
