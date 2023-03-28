class Solution {
    public int mincostTickets(int[] days, int[] costs) {
        int[] dp = new int[days.length+1];
        int monthStart = 1;
        int weekStart = 1;
        
        for(int i=0;i<days.length;i++){
            
            //calculate the total cost till the current day if day pass is bought
            int dayPass = costs[0] + dp[i];
            
            //Find the best possible window for week pass from current day(i)
            while(days[i]-days[weekStart-1]+1>7)
                weekStart++;
            
            //calculate the total cost till current day if week pass is bought for the last week pass window possible
            int weekPass = costs[1] + dp[weekStart-1];
            
            //Find the best possible window for month pass from current day(i)
            while(days[i]-days[monthStart-1]+1>30)
                monthStart++;
            
            //calculate the total cost till current day if month pass is bought for the last month pass window possible
            int monthPass = costs[2] + dp[monthStart-1];
            
            //Now calculate the lowest ticket cost till current day. This is done by choosing the lowest cost among day pass, week pass(for last 7 days) or month pass (for last 30 days)
            dp[i+1] = Math.min(dayPass,Math.min(weekPass,monthPass));
        }
        return dp[days.length];
    }
}
