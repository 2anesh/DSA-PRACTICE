class Solution {
public:
    vector<int> res;
    vector<int> pattern(int N) {
        if (N <= 0) {
            res.push_back(N);
            return res;
        }
        res.push_back(N);
        pattern(N - 5);
        res.push_back(N);
        return res;
    }
};
