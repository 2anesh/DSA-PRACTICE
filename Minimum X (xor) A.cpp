class Solution {
  public:
    int minVal(int a, int b) {
        // code here
        int ca =  __builtin_popcount(a);
        int cb = __builtin_popcount(b);
        int ans =  0;
        int at = 1;
        if(ca == cb)
            return a;
        else if(ca > cb){
            int m = ca-cb;
            while(m>0){
                if((a & at) > 0){
                    m--;
                    ans += at;
                }
                at <<= 1;
            }
            return (a-ans);
        }
        else{
            int m = cb-ca;
            while(m>0){
                if((a & at) == 0){
                    m--;
                    ans += at;
                }
                at <<= 1;
            }
            return (ans+a);
        }
        return 0;
    }
};
