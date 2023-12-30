class Solution{
  public:
    vector<string> winner(string arr[],int n)
    {
        map<string,int>freq; 
        for (int i=0; i<n; i++){
            freq[arr[i]]++;
        }
        string win = "";
        int vote = 0;
        for (auto &name: freq){
            if (name.second > vote){ 
                win = name.first;
                vote = name.second;
            }
        }
        return {win,to_string(vote)};
    }
};
