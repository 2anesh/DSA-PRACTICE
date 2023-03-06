class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int kthMissing=1,curNum=1;
        int arrInd=0;
        while(k>0){
            if(arrInd<arr.size() && arr[arrInd]==curNum)
            arrInd++;
            else{
                k--;
                kthMissing=curNum;
            }
            curNum++;
        }
     return   kthMissing;
            }
};

