class Solution{
    public:
    //Complete this function
    //Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(int a[], int n)
    {
        //Your code here
        vector<int> presum(n,0);
        for(int i=0;i<n;i++){
            presum[i] = (i==0)?(a[i]):(presum[i-1] + a[i]);
            if(presum[i] == 0 || a[i] == 0)return 1;
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<(i-1);j++){
                if(presum[i]-presum[j] == 0)return 1;
            }
        }
        return 0;
    }
};
