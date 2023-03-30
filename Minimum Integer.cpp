class Solution {
  public:
    int minimumInteger(int N, vector<int> &A) {
        long long sum = 0;
        int mini = INT_MAX;
        for(auto it : A)
         sum += it;
         
         for(int i = 0; i < N; i++){
             if((long long)A[i]*N >= sum){
                 mini = min(mini,A[i]);
             }
         }
         return mini;
    }
};
