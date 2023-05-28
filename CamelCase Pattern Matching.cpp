class Solution {
  public:
    vector<string> CamelCase(int N, vector<string> d, string Pattern) {
        vector<string> ans;
        string cmp;
        for(int j = 0; j < N; j++){
            string str = d[j];
            cmp = "";
            for(int i=0;i<str.size();i++){
                if (str[i] >= 'A' && str[i] <= 'Z') cmp += str[i];
                if (cmp.size() == Pattern.size()) break;
            }
            if (Pattern == cmp) ans.push_back(str);
        }
        if (ans.size() == 0) ans.push_back("-1");
        return ans;
    }
};
