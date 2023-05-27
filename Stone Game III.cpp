class Solution {

/*
turn=0 ==> Alice's turn
turn=1 ==> Bob's turn
*/

public:
    int solve(vector<int>& p,int i,int turn,vector<vector<int>> &dp){
         
        int n = p.size();
        if(i>=n) return 0;
        if(dp[i][turn] != -1) return dp[i][turn];
        
        int res = turn == 1 ? 1000000:-1000000;
        int total = 0;
        int j=i;
       
            if(turn == 0){
			// Taking all the 3 possibilities
               if(j<n){
                   total += p[j];
                   res = max(res,total + solve(p,j+1,1,dp)); 
               }
               if(j+1<n){
                   total += p[j+1];
                   res = max(res,total + solve(p,j+2,1,dp)); 
               }
               if(j+2<n){
                   total += p[j+2];
                   res = max(res,total + solve(p,j+3,1,dp)); 
               }
               
            }
            else{
			// Taking all the 3 possibilities
               if(j<n){
                   res = min(res,solve(p,j+1,0,dp));
               }
               if(j+1<n){
                   res = min(res,solve(p,j+2,0,dp));
               }
               if(j+2<n){
                  res = min(res,solve(p,j+3,0,dp)); 
               }
            }
        
        return dp[i][turn]=res;
    }
    
    int stoneGameII(vector<int>& piles) {
        vector<vector<int>> dp(piles.size()+1,vector<int>(2,-1));
       return solve(piles,0,0,dp);
        
    }
    
    string stoneGameIII(vector<int>& stoneValue) {
        long long int sum = 0;
        for(int i=0;i<stoneValue.size();i++){
            sum += stoneValue[i];
        }
        long long int alice = stoneGameII(stoneValue);
		
		// Calculating Bob's stones
        long long int bob = sum - alice;
        
		// Checking who is the winner
        if(alice>bob) return "Alice";
        if(bob>alice) return "Bob";
        return "Tie";
    }
};
