class Solution {
    public int minCost(int n, int[] cuts) {
        int c = cuts.length;

        Arrays.sort(cuts);
        // place 0 and n
        ArrayList<Integer> cutarray = new ArrayList<>();
        cutarray.add(0);

        for(int i = 0; i < c; i++){
            cutarray.add(cuts[i]);
        }
        cutarray.add(n);

        int dp[][] = new int[c + 1][c + 1];
        for(int rows[] : dp){
            Arrays.fill(rows , -1);
        }
        
        return helper(n, cuts, 1, c , cutarray, dp);
     }

    public int helper(int n, int cuts[], int i, int j,  ArrayList<Integer> cutarray, int dp[][]){

            // base case
       if(i > j){
            return 0;
        }

        if(dp[i][j] != -1){
              return dp[i][j];
        }

        int mincost = Integer.MAX_VALUE;
        for(int ind = i; ind <= j; ind++){
          int cost = cutarray.get(j + 1) - cutarray.get(i - 1) 
                     + helper(n, cuts, i, ind - 1 , cutarray, dp) 
                     + helper(n, cuts, ind + 1,j, cutarray, dp);

                       mincost = Math.min(mincost, cost);
        }

            dp[i][j] = mincost;
            return dp[i][j];
     }
}
