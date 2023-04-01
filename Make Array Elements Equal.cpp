class Solution {
  public:
    long long int minOperations(int N) {
       long long  int n = N/2;
        if(N%2 != 0) return (n*(n+1));
        else return (n*N)/2;
    }
};
