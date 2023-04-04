int minSteps(string s) {
    int i=0;
    int ca=0;
    int cb=0;
    for(int i=0;i<s.size();i++){
        if(i==0){
            if(s[i]=='a')ca=1;
            else cb=1;
            continue;
        }
        if(s[i]==s[i-1])continue;
        if(s[i]=='a')ca++;
          else cb++;
    }
    int ans=0;
     return min(ca,cb)+1;
    
}
