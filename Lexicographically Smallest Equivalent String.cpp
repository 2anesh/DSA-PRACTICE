class Solution {

    char dfs(unordered_map<char, vector<char>>& mapping, char input, unordered_set<char>& visited) {

        if (visited.count(input) > 0) {

            return input;

        }

        visited.insert(input);

        char ret = input;

        for (const auto ch : mapping[input]) {

            ret = min(ret, dfs(mapping, ch, visited));

        }

        return ret;

    }

public:

    string smallestEquivalentString(string A, string B, string S) {

        unordered_map<char, vector<char>> mapping;

        for (int i = 0; i < A.size(); ++i) {

            mapping[A[i]].push_back(B[i]);

            mapping[B[i]].push_back(A[i]);

        }

        string ret;

        unordered_map<char, char> memo;

        for (const auto s : S) {

            if (memo.count(s) > 0) {

                ret += memo[s];

                continue;

            }

            unordered_set<char> visited;

            const auto min_char = dfs(mapping, s, visited);

            for (const auto ch : visited) {

                memo[ch] = min_char;

            }

            ret += min_char;

        }

        return ret;

    }

};

