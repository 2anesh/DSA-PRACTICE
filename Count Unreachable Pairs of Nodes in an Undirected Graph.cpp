class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int> parent(n); 
        iota(parent.begin(), parent.end(), 0); 
        
        function<int(int)> find = [&](int p) {
            if (p != parent[p]) 
                parent[p] = find(parent[p]); 
            return parent[p]; 
        }; 
        
        for (auto& e : edges) {
            int p = find(e[0]), q = find(e[1]); 
            if (p != q) parent[p] = q; 
        }; 
        
        unordered_map<int, int> freq; 
        for (int i = 0; i < n; ++i) ++freq[find(i)]; 
        
        long long ans = 0; 
        for (auto& [k, v] : freq) ans += (long long) v * (n - v); 
        return ans/2; 
    }
};
