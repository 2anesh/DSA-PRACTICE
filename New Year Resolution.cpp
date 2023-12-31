class Solution {
    int help(int coins[], int n, int i, int sum) {
        if(sum != 0 && (sum % 20 == 0 || sum % 24 == 0 || sum == 2024)) return 1;
        if(i == n) return 0;
        
        int pick = help(coins, n, i+1, sum+coins[i]);
        if(pick == 1) return 1;
        int notPick = help(coins, n, i+1, sum);
        
        return pick || notPick;
    }
    
    public:
    int isPossible(int n, int coins[]) {
        return help(coins, n, 0, 0);
    }
    
};
