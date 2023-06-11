class Solution{
    public:
    void update(int a[], int n, int u[], int k)
    {
        for(int i=0;i<k;i++){
            a[u[i]-1]++;
        }
        
        for(int i=1;i<n;i++){
            a[i]=a[i]+a[i-1];
        }
    }
};
