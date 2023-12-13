class Solution {
public:
    long long countStrings(int n) {
        // code here
        const long long MOD = 1e9 + 7;

        // Initialize with correct values
        long long one = 1, two = 3, three = 5;

        if (n < 4) {
            if (n == 1)
                return 2 % MOD;
            else if (n == 2)
                return two % MOD;
            else if (n == 3)
                return three % MOD;
        }
        vector<long long int>v(2);
        v[0] = 3;
        v[1] =5;
        for (int i = 4; i <= n; i++) {
            long long x = (v[0]+v[1]) % MOD;
            v[0]=v[1];
            v[1] =x;
        }

        return v[1] % MOD;
    }
};
