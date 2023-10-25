class Solution{
public:
    int fun(int i , int N , int W , int val[] , int wt[] , vector<vector<int>>&dp){
        // base case 
        if(i==0){
            return (W/wt[0])*val[0];
        }
        
        if(dp[i][W]!=-1) return dp[i][W];
        // take 
        int take =0;
        if(wt[i]<=W){
            take = val[i] + fun( i , N , W - wt[i] , val , wt , dp);
        }
        int notTake=0;
        notTake = fun(i-1 , N , W ,  val , wt , dp);
        
        return dp[i][W] = max(take  , notTake);
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here'
        vector<vector<int>>dp(N , vector<int>(W+1 , -1));
        
        return fun(N-1 , N  , W , val , wt , dp);
    }
};
