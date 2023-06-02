class Solution {
public:
    // this dfs functions will recursively perform dfs search for a given i bomb, and visit all the possible reachable neighbours and count the reached nodes in c counter variable, and the visited will maintain the status of neighbour nodes visited.
    void dfs(vector<vector<int>>& gr,vector<bool>& visited,int& c,int& i)
    {
        visited[i]=true; 
        // this will mark the i node as visited
        c++; 
        // since we visited a node we do counter+1
        for(int j=0;j<gr[i].size();j++) 
        // runs the loop for all j nodes that r neighbours to node i
        {
            if(!visited[gr[i][j]]) 
            // if the neighbour is not already visited
            {
                dfs(gr,visited,c,gr[i][j]); 
                // this way we will recursively check all nodes a given i node can reach 
            }
        }
    }
    int maximumDetonation(vector<vector<int>>& bombs) 
    {
        int n=bombs.size();
        vector<vector<int>> gr(n);
        // a directed graph with n nodes/bombs created
        // now lets find the edges
        for(int i=0;i<n;i++)
        // this will check for all bombs i, which r the reachable bombs in its range 
        {
            long long int x1,y1,r1;
            x1=bombs[i][0];
            y1=bombs[i][1];
            r1=bombs[i][2];
            // coordinates of bomb i  and its radius
            for(int j=0;j<n;j++)
            // these r all the bombs we r comparing the bomb i with
            {
                if(i!=j)
                {
                    long long int x,y;
                    x=abs(x1-bombs[j][0]);
                    y=abs(y1-bombs[j][1]);
                    if(x*x+y*y<=r1*r1)
                    // checking if its reachable
                    // if dist btw centres of the bombs is less than the radius of bomb i then upon blasting bomb i , bomb j will also blast bcoz it lies in the blast range
                    {
                        gr[i].push_back(j);
                        // we add this edge to the graph
                    }
                }
            }
        }  

        int ans = INT_MIN;
        for(int i=0;i<n;i++)
        // for all bombs we do dfs and see which bomb has the most blasts ( directly and indirectly )
        {
            int c=0;
            // have the count of bombs blasted upon blasting bomb i
            vector<bool> visited(n,false);
            // to maintain a track of what all nodes were visited 
            dfs(gr,visited,c,i);
            ans=max(ans,c);
            // we store the maximum possible value in ans variable
        }      

        return ans;
    }

};
