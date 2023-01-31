class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {

           int N = scores.size();
           vector<int>idx(N);


           iota(idx.begin() , idx.end() , 0);


           sort(idx.begin() , idx.end() , [&](int aa , int bb)->bool{
               if(ages[aa] == ages[bb]){
                   return scores[aa] < scores[bb];
               }
               return ages[aa] < ages[bb];
           });


           vector<int>dp(N);


           for(int i = 0; i<N ; i++){
               for(int j = 0; j<i ; j++){
                   if(scores[idx[j]] <= scores[idx[i]] || ages[idx[i]]==ages[idx[j]])
                        dp[i] = max(dp[i] , dp[j]);
               }
               dp[i] = dp[i] + scores[idx[i]];
           }

           return *max_element(dp.begin() , dp.end());
    }
};
