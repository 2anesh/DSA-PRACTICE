class Solution {
  public:
    int totalTime(int n, vector<int> &arr, vector<int> &time) {
        map<int,int> mp;
        mp[arr[0]]++;
        int ans=0;
        for(int i=1;i<n;i++){
            if(mp[arr[i]]>0){
                ans+=time[arr[i]-1];
            }
            else{
                ans++;
                mp[arr[i]]++;
            }
        }
        return ans;
    }
};
