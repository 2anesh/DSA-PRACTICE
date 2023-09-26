class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        // Your code goes here
        sort(arr.begin(),arr.end());
        int n=arr.size();
        set<vector<int>> ans;
        vector<vector<int>> res;
        for(int i=0;i<n-3;i++) {
            for(int j=i+1;j<n-2;j++) {
                int l=j+1,r=n-1;
                while(l<r) {
                    int sum=arr[i]+arr[j]+arr[l]+arr[r];
                    if(sum==k) {
                        ans.insert({arr[i],arr[j],arr[l],arr[r]});
                    }
                    if(sum>k) r-=1;
                    else l+=1;
                }
            }
        }
        for(auto cur:ans)
            res.push_back(cur);
        return res;
    }
};
