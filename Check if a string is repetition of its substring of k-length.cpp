class Solution{
public:
	 int kSubstrConcat (int n, string s, int k)
    {
        if(n%k)return 0;
        unordered_map<string,int>mp;
        for(int i=0;i<n;i+=k){
            mp[s.substr(i,k)]++;
            if(mp.size()>2)return 0;
        }
        int ans=0;
        if(mp.size()==2 && n/k==2){
            return 1;
        }
        for(auto it:mp){
           if(ans==0 && it.second>1){
               ans=1;
           }
           else if(ans && it.second>1){
               return 0;
           }
        }
        return ans;
}
};
