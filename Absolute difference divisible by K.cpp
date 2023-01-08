class Solution {
  public:
    long long countPairs(int n, int arr[], int k) {
        
        long long ans = 0;
        int mp[k+1]={0};
        for(int i=0;i<n;i++){
            ans += mp[arr[i]%k];
            mp[arr[i]%k]++;
        }
        return ans;
    }
};
