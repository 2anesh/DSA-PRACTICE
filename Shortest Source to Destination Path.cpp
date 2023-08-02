class Solution {
  public:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        // code here. BFS traversal with DP
        // Queue to maintain the next index to be traversed or checked, provided
        // the next index is 1.
        queue<pair<int, int>> q;
        //Set to keep track of cells we already processed, meaning we have checked for its neighbors.
        // and pushed them to queue for processing.
        set <pair<int,int>> visited;
        // DP or result matrix. res[X][Y] gives the min distance from 0,0
        vector<vector<int>> res(N,vector<int>(M, 300));
        // If start is 0 ot A[X][Y] is 0 we should return -1.
        if (A[0][0] == 0 || A[X][Y] == 0)
            return -1;
        // initialize the distance of the first element to 0.
        res[0][0] = 0;
        q.push(make_pair(0,0));
        while(!q.empty())
        {
            pair<int,int> point = q.front();
            q.pop();
            if (visited.find(point) != visited.end())
                continue;
            visited.insert(point);
            int x = point.first;
            int y = point.second;
            for (int i = 0; i < 4; i++)
            {
                int x1 = x + dx[i];
                int y1 = y + dy[i];
                // Bourndary checks.
                if (x1 < 0 || x1 >= N || y1 < 0 || y1 >= M)
                    continue;
                if (A[x1][y1] == 1 && visited.find(make_pair(x1,y1)) == visited.end())
                {
                    res[x1][y1] = min(res[x1][y1], res[x][y] + 1);
                    q.push(make_pair(x1,y1));
                }
            }
        }
        if (visited.find(make_pair(X,Y)) != visited.end())
            return res[X][Y];
        else 
            return -1;
        
    }
};
