class Solution {
  public int maxNumEdgesToRemove(int n, int[][] edges) {
    if (edges.length < n - 1) return -1; // if edges are less than n - 1, then it's not a valid tree, not all nodes are accessible

    int[] parentAlice = new int[n + 1];
    for (int i = 0; i < parentAlice.length; i++) {
      parentAlice[i] = i;
    }

    // First process the type 3 nodes, this will help us to reduce number of edges required
    int numType3Edges = 0;
    for (int[] edge : edges) {
      if (edge[0] == 3) {
        if (union(parentAlice, edge[1], edge[2])) {
          numType3Edges++;
        }
      }
    }

    int[] parentBob = parentAlice.clone(); // as type 3 are for both alice and bob, clone it for bob as well

    // Process Alice
    int numType1Edges = 0;
    for (int[] edge : edges) {
      if (edge[0] == 1) {
        if (union(parentAlice, edge[1], edge[2])) {
          numType1Edges++;
        }
      }
    }
    if (numType1Edges + numType3Edges + 1 != n) return -1; // if edges are less than n - 1, then type 1 is not a valid tree, not all nodes are accessible

    // Process Bob
    int numType2Edges = 0;
    for (int[] edge : edges) {
      if (edge[0] == 2) {
        if (union(parentBob, edge[1], edge[2])) {
          numType2Edges++;
        }
      }
    }
    if (numType2Edges + numType3Edges + 1 != n) return -1; // if edges are less than n - 1, then type 1 is not a valid tree, not all nodes are accessible
    // return total edges - (number of type 3 + type 2 + type 1 edges required)
    return edges.length - numType1Edges - numType2Edges - numType3Edges;
  }

  int find(int[] parent, int node) {
    if (parent[node] != node) {
      parent[node] = find(parent, parent[node]);
    }
    return parent[node];
  }

  boolean union(int[] parent, int left, int right) {
    int leftParent = find(parent, left);
    int rightParent = find(parent, right);
    if (leftParent == rightParent) return false;
    parent[rightParent] = leftParent;
    return true;
  }
}
