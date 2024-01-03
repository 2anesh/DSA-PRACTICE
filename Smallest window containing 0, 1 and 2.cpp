class Solution {
  public:
    int smallestSubstring(string S) {
        int lastZero =-1, lastOne=-1,lastTwo =-1;
        int ans = INT_MAX;
        for(int i=0;i<S.size();i++){
            if(S[i]=='0')lastZero=i;
            else if(S[i]=='1')lastOne=i;
            else lastTwo=i;
            
            if(lastZero!=-1&&lastOne != -1 &&lastTwo!=-1){
                ans = min(ans,i-min(lastZero,min(lastOne,lastTwo))+1);
            }
        }
        return (ans!=INT_MAX)?ans:-1;
    }
};
