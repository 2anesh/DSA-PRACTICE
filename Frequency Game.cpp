class Solution{
public:
    int LargButMinFreq(int arr[], int n) {
        map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        int mini = INT_MAX;
        int minnum = -1;
        for(auto it : mp){
            if(it.second <= mini){
                mini = it.second;
                minnum = it.first;
            }
        }
        return  minnum;
    }
};
