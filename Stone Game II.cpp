class Solution {
public:
    int stoneGameHelper(vector<int>& piles, int st, int M, vector<vector<int>>& output) {
        if(st == piles.size()) {
            return 0;
        }else if(output[st][M] != -1) return output[st][M];
        int sum = 0;
        int smallAns = INT_MAX;
        for(int i=st; i<piles.size(); i++) sum += piles[i];
        for(int i=st; i<piles.size() && i<st+2*M; i++) {
            smallAns = min(smallAns, stoneGameHelper(piles, i+1, max(M, i-st+1), output));
        }
        return output[st][M] = sum - smallAns;
    }

    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> output(n+1, vector<int>(128, -1));
        return stoneGameHelper(piles, 0, 1, output);
    }
};
