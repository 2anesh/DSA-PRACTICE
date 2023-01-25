class Solution {
public:
vector<int> Bfs(int src, vector<int> &edges) {
    queue<int> q;
    int n = edges.size();
    q.push(src);
    vector<int> dist(n, -1);
    dist[src] = 0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        int next = edges[cur];
        if (next != -1) {
            if (dist[next] == -1) {
                dist[next] = dist[cur] + 1;
                q.push(next);
            }
        }
    }
    return dist;
}

int closestMeetingNode(vector<int> &edges, int node1, int node2) {
    vector<int> v1 = Bfs(node1, edges);
    vector<int> v2 = Bfs(node2, edges);
    int n=edges.size();
    int ans=-1;
    int mn=INT_MAX;
    for (int i = 0; i < n; ++i) {
        if(v1[i]!=-1&&v2[i]!=-1){
            if(max(v1[i],v2[i])<mn){
                ans=i;
                mn=max(v1[i],v2[i]);
            }
        }
    }
    return ans;
}

};
