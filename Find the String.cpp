class Solution{
public:
    unordered_map<string,int>mp;
    string findString(int n, int k) {
        string ans="";
        string temp="";
        for(int i=0;i<n;i++) ans+='0';
        temp+=ans;
        mp[temp]++;
        dfs(temp,ans,k);
        return ans;
    }
    
    void dfs(string curr,string &ans,int k){
        for(int i=k-1;i>=0;i--){
            // leave the first character and take rest n-1
            string temp = curr.substr(1) + (char)(i + '0');
            if(!mp[temp]){
                mp[temp]++;
                ans+=(i+'0');
                dfs(temp,ans,k);
                return;
            }
        }
    }
};
