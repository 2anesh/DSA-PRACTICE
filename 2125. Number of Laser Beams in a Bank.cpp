class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int pre=0,cur=0,res=0;
        for(int i=0;i<bank.size();i++){
            cur=count(bank[i].begin(),bank[i].end(),'1');
            if(cur>0)
                res+=pre*cur,pre=cur;
        }
        return res;
    }
};
