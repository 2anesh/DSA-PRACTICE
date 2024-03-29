class Solution{
    public:
    //Complete this function
    
    void solve(vector<string>&vs, string s, string S, int freq[]){
        
        if(s.size()== S.size()){
            vs.push_back(s);
            return;
        }
        
        for(int i=0; i<S.size(); i++){
            if(!freq[i]){
                s+= S[i];
                freq[i]= 1;
                solve(vs,s, S, freq);
                freq[i]= 0;
                s.pop_back();
            }
        }
    }
    
    vector<string> permutation(string S)
    {
        vector<string>vs;
        string s= "";
        int freq[S.size()];
        for(int i=0; i<S.size(); i++){
            freq[i]= 0;
        }
        solve(vs, s, S, freq);
        sort(vs.begin(), vs.end());
        return vs;
    }
};
