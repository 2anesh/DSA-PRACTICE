class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> map;
        for (int i = 0; i < order.size(); i++) {
            map[order[i]] = i;
        }
        for (int i = 0; i < words.size() - 1; i++) {
            string word1 = words[i], word2 = words[i + 1];
            int j = 0, k = 0;
            while (j < word1.size() && k < word2.size()) {
                if (map[word1[j]] < map[word2[k]]) {
                    break;
                } else if (map[word1[j]] > map[word2[k]]) {
                    return false;
                }
                j++;
                k++;
            }
            if (j == word1.size() && k < word2.size()) {
                continue;
            }
            if (j < word1.size() && k == word2.size()) {
                return false;
            }
        }
        return true;
    }
};
