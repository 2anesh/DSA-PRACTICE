class Solution {

  public:
  long long findMaxSubsetSum(int N, vector<int> &A) {
    int dp[N]; // dp[i] = maximum sum for [0, i] elements if i-th element is included in the subset.
    dp[0] = A[0], dp[1] = A[1] + max(A[0], 0);
    for(int i = 2; i < N; i++) {
        // Either we include (i-1)-th element
       // If not, we are "forced" to include (i-2)-th element
        dp[i] = A[i] + max(dp[i-1], dp[i-2]);
    }
    return max(dp[N-1], dp[N-2]);
}
};
