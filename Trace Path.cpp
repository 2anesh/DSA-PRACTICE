class Solution{
public:
    int isPossible(int n, int m, string s) {
        int h = 0, v = 0;
        int mnl = 0, mxr = 0, mnd = 0, mxu = 0;
        for(char c : s) {
            if(c == 'L') h--;
            else if(c == 'R') h++;
            else if(c == 'U') v++;
            else v--;
            mnl = min(mnl, h);
            mxr = max(mxr, h);
            mnd = min(mnd, v);
            mxu = max(mxu, v);
        }
       
        if(abs(mnl) + mxr >= m || abs(mnd) + mxu >= n) return 0;
        return 1;
    }
};
