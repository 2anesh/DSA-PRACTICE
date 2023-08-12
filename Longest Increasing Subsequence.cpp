class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
     int longestSubsequence(int n, int a[])
    { 
      vector<int>dp; 
      
      dp.push_back(a[0]); 
      
      for(int i=1; i<n; i++){  
          int s=dp.size(); 
          if(a[i]>dp[s-1]) 
            dp.push_back(a[i]); 
          else{
            auto it=lower_bound(dp.begin(),dp.end(),a[i]); 
            *it=a[i]; 
          } 
      }  
      return dp.size(); 
    }
};
