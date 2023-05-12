class Solution {
public:
long long f(int ind, vector<vector<int>>& questions){
 int n = questions.size();

        if(ind >= n){
            return 0;
        }

        long long take = 0, not_take = 0;
        take = questions[ind][0] + f(ind + questions[ind][1]+1, questions);
        not_take = f(ind + 1, questions);
        return max(take, not_take);
    }
    long long f(int ind, vector<vector<int>>& questions,
    vector<long long>& dp){

        int n = questions.size();

        if(ind >= n){
            return 0;
        }

        if(dp[ind] != -1)
            return dp[ind];
         long long take = 0, not_take = 0;
        take = questions[ind][0] + f(ind + questions[ind][1]+1, questions, dp);
        not_take = f(ind + 1, questions, dp);
        return (dp[ind] = max(take, not_take));
    }
    long long mostPoints(vector<vector<int>>& questions) {
       int n = questions.size();
        vector<long long> dp (n, -1);
        return f(0, questions, dp);

    }
};
