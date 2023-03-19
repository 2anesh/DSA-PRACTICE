class Solution {
  public:
    vector<int> getDistinctDifference(int n, vector<int> &arr) {
        vector<int> v;
        unordered_map<int, int> mp;
        mp[0]=0;
        unordered_set<int> s;
        s.insert(arr[0]);
        for(int i=1; i<n; i++){
            mp[i]=s.size();
            s.insert(arr[i]);
        }
        unordered_map<int, int> mp1;
        s.clear();
        mp1[n-1]=0;
        s.insert(arr[n-1]);
        for(int i=n-2; i>=0; i--){
            mp1[i]=s.size();
            s.insert(arr[i]);
        }
        for(int i=0 ; i<n; i++) v.push_back(mp[i]-mp1[i]);
        return v;
    }
};
