class Solution {
public:
    int maxSatisfaction(vector<int>& s) {
        sort(s.begin(), s.end());
        int n=s.size(), sum=0;
        int pos=-1;
        for(int i=n-1; i>=0; i--){
            sum += s[i];
            if(sum < 0){
                pos = n-1-i;
                break;
            }
        }
        if(pos == -1) pos = n-pos-1;

        int ans = 0;
        for(int i=n-1; i>=n-pos; i--) ans += s[i]*(pos-(n-i-1));
        return ans;
    }
};
