class Solution{
  public:
    vector<int> duplicates(int arr[], int n) {
        // code here
        unordered_map<int , int> m;
        for(int i = 0; i< n ;i++)
            m[arr[i]]++;
        
        vector<int> ans;
        for(auto i : m){
            if(i.second > 1)
                ans.push_back(i.first);
        }
        
        if(ans.size() == 0)
            return {-1};
        
        sort(ans.begin() , ans.end());
        return ans;
    }
};
