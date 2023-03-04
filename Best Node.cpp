class Solution {

 

public:

 

    void dfs(int u, int p, vector<int> adj[], vector<vector<long long>> &ans, vector<int> &a, vector<bool> &lef)

    {

        // Flag to keep track if the node is a leaf node

        bool islef = 1;

 

        // Loop through all the adjacent nodes of u

        for (int v : adj[u]) {

            // Check if the adjacent node is not the parent node

            if (p != v) {

                islef = 0;

 

                // Update the maximum value of ans[v][0] and ans[v][1]

                ans[v][0] = max({ans[v][0], ans[u][1] + a[v]});

                ans[v][1] = max({ans[v][1], ans[u][0] - a[v]});

 

                // Call dfs function recursively on the adjacent node

                dfs(v, u, adj, ans, a, lef);

            }

        }

 

        // Update the flag for the current node

        lef[u] = islef;

    }

 

    long long bestNode(int n, vector<int> &A, vector<int> &P) {

 

        // Create a 2D vector with n rows and 2 columns, and initialize all values to -1e18

        vector<vector<long long>> v(n ,vector<long long>(2,-1e18));

 

        // Initialize the values of the first column of v with the values from vector A

        for (int i = 0; i < n; i++) {

            v[i][0] = A[i];

        }

 

        // Decrement all the values in vector P by 1

        for (int &i : P) {

            i--;

        }

 

        // Create an adjacency list using the values in vector P

        vector<int> adj[n];

        for (int i = 1; i < n; i++) {

            adj[i].push_back(P[i]);

            adj[P[i]].push_back(i);

        }

 

        // Create a vector to keep track of leaf nodes

        vector<bool> lef(n, 0);

 

        // Call dfs function on the root node

        dfs(0, -1, adj, v, A, lef);

 

        // Initialize ans variable with -1e18

        long long ans = -1e18;

 

        // Loop through all the nodes and update ans variable with maximum of v[i][0] and v[i][1] for leaf nodes

        for (int i = 0; i < n; i++) {

            if (lef[i]) {

                ans = max({ans, v[i][0], v[i][1]});

            }

        }

 

        // Return the value of ans variable

        return ans;

    }

};
