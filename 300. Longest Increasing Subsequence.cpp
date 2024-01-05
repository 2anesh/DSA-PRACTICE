class Solution {
public:

    int binarySearch(vector<int> &dp, int tar) {
        int i = 0, j = dp.size() - 1;
        while (i <= j) {
            int idx = (i + j) / 2;
            if (tar == dp[idx]) {
                return idx;
            } else if (tar > dp[idx]) {
                i = idx + 1;
            } else {
                j = idx - 1;
            }
        }
        return i;
    }

    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp; dp.push_back(nums[0]);
        for (auto &n:nums) cout << n << " ";
        cout << endl;

        for (int i = 1; i < nums.size(); i++) {
           // cout << nums[i] << endl;
            if (nums[i] < dp[0]) dp[0] = nums[i];
            else if (nums[i] > dp[dp.size() - 1]) dp.push_back(nums[i]);
            else {
                int site = binarySearch(dp, nums[i]);
                dp[site] = nums[i];
            }
        }
        return dp.size();
    }
};
