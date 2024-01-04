class Solution {
  public:
    int singleElement(int arr[] ,int N) {
        // code here
        unordered_map<int, int>mpp;
        for(int i=0; i<N; i++){
            mpp[arr[i]]++;
        }
        for(auto &it:mpp){
            if(it.second==1) return it.first;
        }
        return -1;
    }
};
