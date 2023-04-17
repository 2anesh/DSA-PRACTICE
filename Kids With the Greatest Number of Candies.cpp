class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        
        vector<bool>v;
        int n = candies.size() , maxCandies = 0;
        for(int i = 0 ; i < n ; i++)
            if(candies[i] > maxCandies)
               maxCandies = candies[i];
        
        for(int i=0;i<n;i++){
            if((candies[i]+extraCandies)>=maxCandies){
                v.push_back(true);
            }else{
                v.push_back(false);
            }
        }
        return v;
    }
};
