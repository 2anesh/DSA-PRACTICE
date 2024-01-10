class Solution{
public:
int longSubarrWthSumDivByK(int arr[], int n, int k)
{
      unordered_map<int,int>mp;
        int ans=0,sum=0;
        mp[0]=-1;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            int r=sum%k;
            if(r<0) r+=k;
            if(mp.find(r)==mp.end()) mp[r]=i;
            else ans=max(ans,i-mp[r]);
        }
        return ans;
}
};
