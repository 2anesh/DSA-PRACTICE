class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {
        
        // Your code here
        if(str1.size()!=str2.size()) return false;
        unordered_map<char,char>mp;
        unordered_map<char,char>mp2;
        for(int i=0;i<str1.size();i++){
            if(mp.find(str1[i])==mp.end() && mp2[str2[i]]) return false;
            if(mp.find(str1[i])!=mp.end()){
                if(mp[str1[i]]==str2[i]) continue;
                else return false;
            }
            else{ mp[str1[i]] = str2[i];
            mp2[str2[i]] = 1;
            }
           
        }
        return true;
        
        
    }
};
