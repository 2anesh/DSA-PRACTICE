class Solution{
public:
    vector<int> optimalArray(int n,vector<int> &arr){
        // Code here
        
        vector<int>ans(n,0);
        
        for(int i=1;i<n;i++)
        {
            
            int x=abs(arr[i]-arr[i/2]);
            
            ans[i]=ans[i-1]+x;
        }
        
        return ans;
    }
