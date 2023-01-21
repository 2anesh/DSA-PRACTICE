class Solution {
public:

bool isValid(string s){
    if(s.length() < 1) return false;
    if(s[0] == '0' && s.length() >= 2){
        return false;
    }
    long long num = stol(s);
    if(0 <= num && num <= 255) return true;
    return false;
}
vector<string> restoreIpAddresses(string s) {        
    int n = s.length();
    vector<string> ans;
    for(int i=1;i<n-2;i++){
        string n1 = s.substr(0,i);
        // if(!isValid(n1)) continue;
        for(int j=i+1;j<n-1;j++){
            string n2 = s.substr(i,j-i);
           
            for(int k=j+1;k<n;k++){
                
                string n3 = s.substr(j,k-j);
                string n4 = s.substr(k);
                string tmp = "";
                if(!isValid(n1 )|| !isValid(n2) || !isValid(n3) || !isValid(n4) ) continue;
                tmp = n1+'.'+n2+'.'+n3+'.'+n4;
                ans.push_back(tmp);
            }
        }
        
    }       
    return ans;
}
};
