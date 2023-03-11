class Solution {
  public:
    vector<int> solveQueries(int n, int num, vector<int> &a, vector<vector<int>> &Q) 
    {
       vector<int> v(n, 0);
       for(int i=0; i<n; i++)
       {
           int ele = a[i];
           int f = 0;
           for(int j=i; j<n; j++)
           {
               if(a[j]==ele)
               {
                   f++;
               }
           }
           v[i] = f;
       }
       
       vector<int> ans;
       for(int i=0; i<Q.size(); i++)
       {
           int l = Q[i][0];
           int r = Q[i][1];
           int k = Q[i][2];
           int a = 0;
           for(int j=l; j<=r; j++)
           {
               if(v[j]==k)
               {
                   a++;
               }
           }
           ans.push_back(a);
       }
       
       return ans;
    }
};
