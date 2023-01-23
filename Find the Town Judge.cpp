class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<vector<int> > adj(n+1);
        for(int i = 1; i<=n ; i++)adj[i].push_back(i);

        for(int i = 0 ; i<trust.size() ; i++){
            adj[trust[i][1]].push_back(trust[i][0]);
        }

        vector<int>cont;
        for(int i = 1; i<=n ; i++){
            vector<int>is_trusted(n+1 , false);
            for(int e: adj[i]){
                is_trusted[e] = 1;
            }

            bool ff = 1;
            for(int j = 1; j<=n ; j++)ff &= is_trusted[j];
            if(ff){
                cont.push_back(i);
            }
        }

        vector<int>ct(n+1);
        for(int i = 1; i<=n ; i++){
            for(int e : adj[i]){
                ct[e]++;
            }
        }

        for(auto e:cont){
            if(ct[e] == 1)return e;
        }

        return -1;
    }
};
