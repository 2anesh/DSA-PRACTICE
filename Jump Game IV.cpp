class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n=arr.size();
        if(n==1)
        return 0;
        map<int,vector<int>>mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]].push_back(i);
        }
        vector<bool>vis(n,false);
        vis[0]=true;
        queue<int>q;
        q.push(0);
        int ans=0;
        while(!q.empty()){
            int l=q.size();
            while(l--){
                int curr=q.front();
                q.pop();
                cout<<curr<<" ";
                if(curr+1<n && vis[curr+1]==false){
                    if(curr+1==n-1)
                    return ans+1;
                    vis[curr+1]=false;
                    q.push(curr+1);
                }
                if(curr-1 >= 0 && vis[curr-1]==false){
                    q.push(curr-1);
                    vis[curr-1]=true;
                }
                if(mp.find(arr[curr])!=mp.end()){
                    for(auto v:mp[arr[curr]] ){
                         
                        if(vis[v]==false){
                        if(v==n-1)
                        return ans+1;
                        vis[v]=true;
                        q.push(v);
                        //  cout<<v;
                        }
                    }
                    mp.erase(arr[curr]);
                }
            }
            ans++;
        }
        return ans;
    }
};
