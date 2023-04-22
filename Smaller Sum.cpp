class Solution{
public:
     vector<long long> smallerSum(int n,vector<int> &arr){
        // Code here
        vector<int> gg(n,0);
        iota(begin(gg),end(gg),0);
        auto cmp = [&](int &a,int &b)
        {
            return arr[a]<arr[b];
        };
        sort(begin(gg),end(gg),cmp);
        vector<long long> ans(n,0);
        
        long long sum = 0, tmp = arr[gg[0]];
        
        for(int i=1;i<n;i++)
        {
            if(arr[gg[i-1]]==arr[gg[i]])
            {
                tmp+=arr[gg[i]];
            }
            else
            {
                sum+=tmp;
                tmp=arr[gg[i]];
            }
            ans[gg[i]]=sum;
        }
        return ans;
    }
};
