class Solution{
    public:
    //Function to count the frequency of all elements from 1 to N in the array.
    void frequencyCount(vector<int>& arr,int N, int P)
    { 
        // code here
        unordered_map<int,int> mp;
        for(int i=0;i<N;i++){
            mp[arr[i]]++;
        }
        for(int i=0;i<N;i++){
            arr[i]=0;
        }
        for(auto i:mp){
            if(i.first<=N ){
                arr[i.first-1]=i.second;
            }
        }
    }
};
