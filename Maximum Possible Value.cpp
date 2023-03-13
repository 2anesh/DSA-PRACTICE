class Solution {
  public:
    // Time Complexity :- O(n);
    // Space Compleixty :- O(1);
    long long maxPossibleValue(int n,vector<int> a, vector<int> b) {
        long long int count=0;
        long long int ans=0;
        int mini=INT_MAX;
      for(int i=0;i<n;i++)
      {
          count+=(long long)(b[i]/2);
          ans+=(long long )a[i]*(b[i]-b[i]%2);
          if(b[i]>=2)
          mini=min(a[i],mini);
      }
      if(count%2!=0)
      ans-=mini*2;
      return ans;
      
    }
};
