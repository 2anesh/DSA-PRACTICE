class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        

        // using concepts of dijkstra's algorithm ;
        vector< pair<int,int>> adj[n] ;
        for(auto it : flights) {
            adj[it[0]].push_back({it[1] , it[2]}) ;
        }

        // { stop , {node , dist}} ;
        queue< pair<int , pair<int,int>>> q ;
        q.push({0 , {src , 0} }) ;

        vector<int> dist(n , 1e9) ;
        dist[src] = 0 ;
 
        while(!q.empty()) {
            auto it = q.front() ;
            q.pop() ;

            int stop = it.first ;
            int node = it.second.first ;
            int cost = it.second.second ;

            if( stop > k ) continue ;

            for(auto it : adj[node]) {
                int adjNode = it.first ;
                int edgeWeight = it.second ;

                if(cost + edgeWeight < dist[adjNode] && stop <= k ) {
                    dist[adjNode] = cost + edgeWeight ;
                    q.push({stop + 1 , {adjNode , cost+edgeWeight }}) ;
                }
            }
        }
        if(dist[dst] == 1e9) return -1 ;
        return dist[dst] ;
    }
};
