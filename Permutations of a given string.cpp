class Solution
{
    void solve(int n,set<string>&st,string temp,string &s,vector<int>&vis){
         if(temp.size()==n){
             st.insert(temp);
             return;
         }
         for(int i=0;i<n;i++){
             if(!vis[i]){
                  temp+=s[i];
                  vis[i]=1;
             solve(n,st,temp,s,vis);
                temp.pop_back();
                vis[i]=0;
         }
   }
  }
	public:
		vector<string>find_permutation(string s)
		{
		    int n=s.size();
		  set<string>st;
          string temp="";
          vector<int>vis(n,0);
        solve(n,st,temp,s,vis);
         vector<string>ans;
        for(auto it:st){
            ans.push_back(it);
        }
        return ans;
    }
		
};
