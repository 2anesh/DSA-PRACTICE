class Solution{
    public:
    int findWinner(int n, int A[]){
       
        int check = 0;
        for(int i=0; i<n; i++)
            check ^= A[i];
       
        if(check == 0)
            return 1;
        else
            return (n%2)+1;
    }
};
