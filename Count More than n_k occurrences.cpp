class Solution
{
    public:
    int countOccurence(int arr[], int n, int k) {
        unordered_map<int,int> m;
        int temp=n/k;
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            m[arr[i]]++;
        }
        for(auto it:m)
        {
            if(it.second>temp)
            {
                cnt++;
            }
        }
        return cnt;
    }
};
