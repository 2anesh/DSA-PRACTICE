class Solution{   

public:

int f(int ind , int col  ,vector<vector<int>>&colors,vector<vector<int>>&dp){

    int n =colors.size() ;

    if(ind==n)return 0 ;

    if(dp[ind][col]!=-1) return dp[ind][col] ;

    if(col==0) dp[ind][col]= colors[ind][0]+ min(f(ind+1, 1,colors,dp) , f(ind+1,2,colors,dp)) ;

    else if(col==1) dp[ind][col]= colors[ind][1] +min(f(ind+1, 0,colors,dp) ,f(ind+1,2,colors,dp)) ;

    else if(col==2) dp[ind][col]= colors[ind][2] +min(f(ind+1,0,colors,dp) ,f(ind+1,1,colors,dp)) ;

    return dp[ind][col]  ;

}

    int minCost(vector<vector<int>> &colors, int n) {

        // Write your code here.

        int ind=0 ;

        vector<vector<int>>dp(n+1,vector<int>(3,-1)) ;

        return min({f(ind,0,colors,dp) , f(ind,1,colors,dp),f(ind,2,colors,dp)}) ;

    }

 

};
