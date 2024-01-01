class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());     
        int k = 0; 
        for (auto &x : s) {
            if (k < g.size() && g[k] <= x) ++k; 
        }
        return k; 
    }
};
