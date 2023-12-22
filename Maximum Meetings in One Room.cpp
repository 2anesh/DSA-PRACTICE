class Solution{
public:
    vector<int> maxMeetings(int n,vector<int> &S,vector<int> &F){
        vector<pair<pair<int,int>,int>> arr(n);
        vector<int> sol;
        for(int i=0;i<n;i++){
            arr[i].first.first=F[i];
            arr[i].first.second=S[i];
            arr[i].second=i+1;
        }
        sort(arr.begin(),arr.end());
        int idx=0;
        sol.push_back(arr[0].second);
        for(int i=1;i<n;i++){
            if(arr[idx].first.first<arr[i].first.second){
                idx=i;
                sol.push_back(arr[i].second);
            }
        }
        sort(sol.begin(),sol.end());
        return sol;
    }
};
