class Solution {
public:
    int partitionString(string s) {
        int max=0,i=0;
        while(i<s.size())
        {
            unordered_map<char ,int> map;
            while(map[s[i]]==0 &&i<s.size())
            {
                map[s[i]]++;
                i++;
            }
            max++;
        }
        return max;
    }
};
