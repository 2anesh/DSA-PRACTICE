class Solution{

  public:

  vector<long long int> countZero(int n, int k, vector<vector<int>>& arr){

      //Code Here

      #define ll long long int

      vector<ll> ans;

      vector<bool> vis1(n+1,0), vis2(n+1,0);

      ll i=0,remrow=n,remcol=n,tot=n*n;

      while(k--) {

          ll x=arr[i][0];

          ll y=arr[i][1];

          if(vis1[x]==0) {

              tot-=remrow;

              remcol--;

              vis1[x]=1;

          }

          if(vis2[y]==0) {

              tot-=remcol;

              remrow--;

              vis2[y]=1;

          }

          ans.push_back(tot);

          i++;

      }

      return ans;

  }

};
