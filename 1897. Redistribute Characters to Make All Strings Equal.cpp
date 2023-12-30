class Solution {
public:
    bool makeEqual(vector<string>& words) {
        vector<int> freq(26); 
        for (auto& word : words) 
            for (auto& ch : word) ++freq[ch-'a']; 
        for (int i = 0; i < 26; ++i) 
            if (freq[i] % size(words)) return false; 
        return true; 
    }
};
