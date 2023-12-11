class Solution{   
public:
    long maximumSumSubarray(int K, vector<int> &Arr , int N){
        long long sum = 0;
        long long best = 0;
        
        for(int i = 0; i < K; i++)
            sum += Arr[i];
            
        best = sum;
        
        for(int i = K; i < N; i++){
            sum -= Arr[i - K];
            sum += Arr[i];
            
            best = max(best, sum);
        }
        
        return best;
    }
};
