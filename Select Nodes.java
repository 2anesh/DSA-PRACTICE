class Solution{

    

    public int fun(int node, int CanLightUp, int parent, 

    ArrayList<ArrayList<Integer>> adj, int [][] dp){

        int ans = 0;

        if(dp[node][CanLightUp] != 0) return dp[node][CanLightUp]; 

        for(Integer child: adj.get(node)){

            if(parent != child){

                if(CanLightUp == 1){

                    int fun0 = fun(child, 0, node, adj, dp);

                    int fun1 = fun(child, 1, node, adj, dp);

                    ans += Math.min(fun0, fun1+1);

                }else{

                    int fun1 = fun(child, 1, node, adj, dp);

                    ans += fun1 + 1;

                }

            }

        }

        return dp[node][CanLightUp] = ans;

    }

    public int countVertex(int N, int[][] edges){

        ArrayList<ArrayList<Integer>> adj = new ArrayList<>();

        for(int i=0; i<N+1; i++) adj.add(new ArrayList<>());

        for(int i=0; i< edges.length; i++) {

            adj.get(edges[i][0]).add(edges[i][1]);

            adj.get(edges[i][1]).add(edges[i][0]);

        }

        int [][] dp = new int[N+1][2];

        // n1 mean we do a light up and 0 mean we doesn't do a light up

        return Math.min(fun(1, 1, -1, adj, dp)+1, fun(1, 0, -1, adj, dp));

    }

}
