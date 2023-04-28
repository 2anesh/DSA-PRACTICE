class Solution {
public:
    bool is_similar(string &a, string &b) {
        int n = 0;
        for (int i = 0; i < a.size(); i++)
            if (a[i] != b[i] && ++n > 2)
                return false;
        return true;
    }
    int numSimilarGroups(vector<string>& strs) {
        int color = 0 ; 
        unordered_map<int, vector<string>> mp ;
        mp[0].push_back(strs[0]); 
        for(int i=1; i < strs.size(); i++){
            bool flag = false ;
            int prev_color = -1; 
            for(auto x: mp){
                for(auto y:x.second){
                    bool temp = is_similar(strs[i], y); 
                    if(temp && flag){
                        for(auto z: mp[prev_color]) mp[x.first].push_back(z);
                        mp.erase(prev_color);
                        prev_color = x.first ; 
                        break ;
                    }
                    else if(temp){
                        mp[x.first].push_back(strs[i]); 
                        prev_color = x.first; 
                        flag = true;
                        break ;
                    }
                }
            }
            if(flag == false){ color ++; mp[color].push_back(strs[i]); }
        }
        return mp.size(); 
    }
};
