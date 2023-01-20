class Solution
{
  public:
  int maxWeightCell(int N, vector<int> Edge)
  {
     unordered_map<int,int>mp;
     for(int i=0;i<N;i++){
         mp[Edge[i]]+=i;
     }
     int maxi=0;
     int ans=0;     
     for(auto it:mp){
         if(it.first!=-1 and it.second>=maxi)
         {
             maxi=it.second;
             ans=it.first;
         }         
     }
     return ans;
  }
};
