class Solution {
public:
    // concept used : substring , palindrome , recursion
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> ds;
        find(s,res,ds,0);
        return res;
    }
    void find(string s,vector<vector<string>>&res,vector<string>&ds,int ind){
        if(ind==s.size()) 
        {
            res.push_back(ds);
            return;
        }
        for(int i=ind;i<s.size();i++){
          if(ispal(s,ind,i)){
              ds.push_back(s.substr(ind,i-ind+1));
              find(s,res,ds,i+1);
              ds.pop_back();
          }
        }
    }
    bool ispal(string s,int st,int en){
      while(st<=en){
          if(s[st++]!=s[en--]){
              return false;
          }
      }
      return true;
    }
};
