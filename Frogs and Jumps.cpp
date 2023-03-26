class Solution {
  public:
    int unvisitedLeaves(int n, int leaves, int frogs[]) {
        sort(frogs, frogs + n);
        vector<int> v(leaves + 1);
        
        for(int i=0; i<n; i++) {
            if(frogs[i] > leaves) continue;
            if(!v[frogs[i]]) {
                for(int j=frogs[i]; j<=leaves; j+=frogs[i]) v[j] = 1;
            }
        }
        int ans = 0;
        for(int i : v) ans += !i;
        return ans - 1;
    }
};
