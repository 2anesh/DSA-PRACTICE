class Solution{
public:
 
int isDivisible(string s){
    int even=0,odd=0;
    for(int i=0;i<s.length();i++){
        if(i%2==0){
            if(s[i]=='1')
             even++;
        }
       else{
           if(s[i]=='1')
            odd++;
       }
    }
    return (even-odd)%3==0;
}
 
};
