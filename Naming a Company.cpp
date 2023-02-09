class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        unordered_set<string> seen(ideas.begin(), ideas.end()); 
        unordered_set<char> first; 
        vector<vector<int>> freq(26, vector<int>(26)); 
        for (auto& idea : ideas) 
            first.insert(idea[0]); 
        for (auto idea : ideas) {
            char c = idea[0]; 
            for (auto& cc : first) {
                idea[0] = cc; 
                if (!seen.count(idea)) ++freq[c-'a'][cc-'a']; 
            }
        }
        long long ans = 0; 
        for (auto idea : ideas) {
            char c = idea[0]; 
            for (auto& cc : first) {
                idea[0] = cc; 
                if (!seen.count(idea)) ans += freq[cc-'a'][c-'a']; 
            }
        }
        return ans; 
    }
};
