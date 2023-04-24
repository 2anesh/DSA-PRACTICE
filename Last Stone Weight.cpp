class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n=stones.size();
        int m1,m2;
        while(n>1){
            sort(stones.begin(),stones.end());
           
            m1=stones[n-1];
            m2=stones[n-2];
            if(m1==m2){
                stones.erase(stones.begin()+(n-1));
                stones.erase(stones.begin()+(n-2));
            }
            else if(m1>m2){
                stones.erase(stones.begin()+(n-1));
                stones.erase(stones.begin()+(n-2));
                stones.push_back(m1-m2);
            }
            else if(m2>m1){
                stones.erase(stones.begin()+(n-1));
                stones.erase(stones.begin()+(n-2));
                stones.push_back(m2-m1);
            }
            n=stones.size();
        }
        if(n==0){
            return 0;
        }
        else{
            return stones[0];
        }
    }
};
