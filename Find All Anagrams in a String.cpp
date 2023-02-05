class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> x;
        vector<int> a(27,0);
        vector<int> b(27,0);
        int k = p.length();
        int count = 0;
        for(int h = 0; h < p.length();h++){
            a[p[h] - 'a']++;
        }
        
        for(int i = 0,j = 0;j < s.length();j++ ){
            b[s[j]-'a']++;
            if(j-i+1 == k){
                if(a == b){
                    x.push_back(i);
                }
                b[s[i]-'a']--;
                i++;
            }
        }
        return x;
    }
};
