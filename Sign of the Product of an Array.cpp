class Solution {
public:
    int arraySign(vector<int>& nums) {
        int l=0;
        for(auto it:nums){
            if(it==0)return 0;
            if(it<0)l++;
            
        }
        if(l%2)return -1;
        else return 1;
    }
};
