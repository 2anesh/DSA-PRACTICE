class Solution{
    public:
        int t[405][405];
        int maxt(vector<int>&a,int i,int j){
            if(i>j)
            {
                return 0;
            }
            int ans=INT_MIN;
            if(t[i][j]!=-1)
            {
            return t[i][j];
            }
            for(int k=i;k<=j;k++){
                ans=max(ans,maxt(a,i,k-1)+maxt(a,k+1,j)+a[k]*(i-1>=0?a[i-1]:1)*(j+1<a.size()?a[j+1]:1));
            }
            return t[i][j]=ans;
        }
    int maxCoins(int N, vector<int> arr) {
        memset(t,-1,sizeof(t));
        int i=0;
        int j=arr.size()-1;
        return maxt(arr,i,j);
        //Write your code here
    }
};
