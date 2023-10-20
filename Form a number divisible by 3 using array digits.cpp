class Solution {
  public:
    int isPossible(int N, int arr[]) {
        long ans=0;
        for(int i=0;i<N;i++)  ans+=arr[i];
        return ans%3==0;
    }
};
