class Solution {
  public:
    vector<int> leastPrimeFactor(int n) {
        // initialize the vector
        vector<int> ans(n+1);
        ans[1] = 1;
        
        // initialize all numbers as prime 
        for(int i = 2;i <= n; i++){
            ans[i]=i;
        }
        
        // sieve of eratosthenes
        for(int i = 2; i*i <= n; i++){
            // if prime, mark all multiples of i with their least prime factor
            if(ans[i]==i){
                for(int j = i*i; j <= n; j += i){
                    if(ans[j] == j){
                        ans[j] = i;
                    }
                }
            }
        }
        return ans;
    }
};

