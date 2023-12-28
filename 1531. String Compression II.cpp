class Solution {
private:
    int compress(int len) {
        if (len <= 1) return len;
        return (int)log10(len) + 2;
    }    
    int dfs(int i, int k, string &s, vector<int> &conseqLen, vector<vector<int>> &dp) {
        if (i >= s.size()) return 0;
        if (dp[i][k] != INT_MAX) return dp[i][k];
        int totalLen = conseqLen[i];
        int skipLen = 0;
        bool reach = true;
        int kCnt = k;
        while (reach) {
            int nextI = i + totalLen + skipLen; 
            for (int j = 0; j <= min(totalLen, kCnt); j++) {
                int compressLen = compress(totalLen - j);
                int nextLen = dfs(nextI, kCnt - j, s, conseqLen, dp);
                dp[i][k] = min(dp[i][k], compressLen + nextLen);
            }
            reach = false;
            while (nextI < s.size() && s[nextI] != s[i] && kCnt >= conseqLen[nextI]) {
                kCnt -= conseqLen[nextI];
                skipLen += conseqLen[nextI];
                nextI += conseqLen[nextI];
            }
            if (nextI < s.size() && s[nextI] == s[i]) {
                reach = true;
                totalLen += conseqLen[nextI];
            }
        } 
        return dp[i][k];
    }
public:
    int getLengthOfOptimalCompression(string s, int k) {
        vector<vector<int>> dp(s.size(), vector<int>(k + 1, INT_MAX));
        vector<int> conseqLen(s.size(), 0);
        conseqLen.back() = 1;
        for (int i = s.size() - 2; i >= 0; i--) {
            if (s[i] == s[i + 1]) {
                conseqLen[i] = conseqLen[i + 1] + 1;
            } else {
                conseqLen[i] = 1;
            }
        }
        return dfs(0, k, s, conseqLen, dp);
    }
};
