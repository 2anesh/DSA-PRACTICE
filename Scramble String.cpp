class Solution {
public:
map<pair<string,string>,bool>m;
bool func(string s1,string s2){
    if(s1==s2){
        return true;
    }
    if(m.count({s1,s2})){
        return m[{s1,s2}];
    }
    int n=s1.size();
    for(int i=0;i<n-1;i++){
        if(func(s1.substr(0,i+1),s2.substr(0,i+1)) && func(s1.substr(i+1),s2.substr(i+1))){
            return m[{s1,s2}]=true;
        }
        if(func(s1.substr(0,i+1),s2.substr(n-i-1)) && func(s1.substr(i+1),s2.substr(0,n-i-1))){
            return m[{s1,s2}]=true;
        }
    }
    return m[{s1,s2}]=false;
}
    bool isScramble(string s1, string s2) {
        return func(s1,s2);
        //return ans;
    }
};
