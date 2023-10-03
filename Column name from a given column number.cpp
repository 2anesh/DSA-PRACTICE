class Solution{
    public:
    string colName (long long int n)
    {
        string ans = "";
        while(n){
            n--;
            char a = 'A' + n%26;
            ans.push_back(a);
            n/= 26;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
