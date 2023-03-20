class Solution {
public:
    bool canPlaceFlowers(vector<int>& flower, int n) {
        if(n == 0){
            return true;
        }
        int length = flower.size();
        for(int i=0;i<length;i++){
            if(flower[i] == 0 && (i==0 || flower[i-1] == 0) && (i==length-1 || flower[i+1] == 0)){
                n--;
                flower[i] = 1;
                if(n == 0){
                    return true;
                }
            }
        }
        return false;
    }
};
