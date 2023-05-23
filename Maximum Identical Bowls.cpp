class Solution {
  public:
    int getMaximum(int n, vector<int> &arr) {
        
        long long int sum=0;
        for(auto it:arr)sum+=it;
        for(int i=0;i<n;i++){
            if(sum%(n-i)==0)return n-i;
        }
        return 0;
    }
};
