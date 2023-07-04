class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        int count=0;
        long long mul=1;
        for(int i=0;i<n;i++){
            if(a[i]<k){
                count++;
            }
            mul=a[i];
            for(int j=i+1;j<n;j++){
                mul*=a[j];
                if(mul<k){
                    count++;
                }
                else{
                    break;
                }
            }
        }
        return count;
    }
};
