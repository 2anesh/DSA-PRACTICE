class Solution{
public:
    int minimumTime(int N,int cur,vector<int> &pos,vector<int> &time){
        int mn = INT_MAX;
        for(int i = 0; i<N; i++){
            int temp = abs( cur - pos[i] ) * time[i];
            mn = min(mn , temp);
        }
        return mn;
    }
};
