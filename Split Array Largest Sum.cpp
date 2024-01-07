class Solution {
  public:
  bool check(int arr[],int K,int N,int mid)
  {
      int ans=1;
      int sum=0;
      for(int i=0;i<N;i++)
      {
          sum+=arr[i];
          if(sum>mid)
          {
              sum=arr[i];
              ans++;
          }
      }
      if(ans<=K)
      {
          return true;
      }
      else
      {
          return false;
      }
  }
    int splitArray(int arr[] ,int N, int K) {
        int low=INT_MIN,high=0;
        int ans;
        for(int i=0;i<N;i++)
        {
            low=max(low,arr[i]);
            high+=arr[i];
        }
        while(low<=high)
        {
          int mid=(low+high)/2;
        if(check(arr,K,N,mid))
        {
            ans=mid;
            high=mid-1;
        }
        else
        {
           low=mid+1; 
        }
        }
        return ans;
    }
};
