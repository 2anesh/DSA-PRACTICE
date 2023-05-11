class Solution {
  public:
    int minimumSum(string s) {
    // code here
    int lo=0,hi=s.length()-1;
    while(lo < hi){
        if(s[lo] != s[hi]){
            if(s[lo] == '?')s[lo] = s[hi];
            else if(s[hi] == '?')s[hi] = s[lo];
            else return -1;
        }
        lo++;
        hi--;
    }
    
    int cnt = 0,prev = -1;
    for(const auto& x: s){
        if(isalpha(x)){
            if(prev != -1)cnt += abs(prev-x);
            prev = x;
        }
    }
    
    return cnt;
}
};
