class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
        //code
        long long ans=1e9;
        sort(a.begin(), a.end());
        for(long long i=0; i<n-m+1; i++){
            ans=min(ans, a[i+m-1]-a[i]);
        }
        return ans;
    }   
};
