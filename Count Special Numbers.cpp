class Solution {
  public:
    int countSpecialNumbers(int n, vector<int> arr) {
        // Code here
        sort(arr.begin(),arr.end());
        int ans=0;
        unordered_map<int,int> mp;
        
        for(int i=0;i<n;i++)
          mp[arr[i]]++;
        
        for(int i=1;i<n;i++){
            if(mp[arr[i]]==-1)
            {
                continue;
            }
            else if(mp[arr[i]]>1)
            {
                ans=ans+mp[arr[i]];
                mp[arr[i]]=-1;
            }
            else{
            for(int j=0;j<i && arr[j]<=arr[i]/2;j++)
            {
                if(arr[i]%arr[j]==0)
                {
                    ans++;
                    break;
                }
            }
            }
        }
            
        
        return ans;
    }
};
