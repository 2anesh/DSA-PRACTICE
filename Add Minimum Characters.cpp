class Solution{   
public:
    int addMinChar(string str){    
        //code here
        int n=str.size(),ans=0;
        int i=0,j=n-1;
        while(i<=j){
            if(str[i]==str[j]){
                i++;j--;
            }else{
                ans++;
                i=0;j=n-1-ans;
            }
        }
        return ans;
        
    }
};

