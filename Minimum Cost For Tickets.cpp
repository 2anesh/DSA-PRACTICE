class Solution {
public:
vector<int>dp;
    int helper(vector<int>& days, vector<int>& costs,int startIndex)
    {
        int n = days.size();
        if(startIndex>=n) return 0;
        if(dp[startIndex])return dp[startIndex];
        //ek din ka ticket
        int pass_day_cost = costs[0]+helper(days,costs,startIndex+1);
        int i;
        for(i=startIndex;i<n && days[i]<days[startIndex]+7;i++);
        int pass_week_cost = costs[1]+helper(days,costs,i);

        for(i=startIndex;i<n && days[i]<days[startIndex]+30;i++);
        int pass_month_cost=costs[2]+helper(days,costs,i);

        return dp[startIndex]=min({pass_day_cost,pass_week_cost,pass_month_cost});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n =days.size();
        dp.resize(n+1);
        return helper(days,costs,0);
    }
};
