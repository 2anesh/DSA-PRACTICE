class Solution{   
public:
    int appleSequences(int n, int m, string arr){
        // code here 
        
        int cnt=0;
        int ans=-1e9;
        int i=0,j=0;
        while(j<n){
            if(arr[j]=='O')
                cnt++;
                
            if(cnt==m)
                ans=max(ans,(j-i+1));
            else if(cnt>m){
                while(cnt>m){
                    if(arr[i]=='O')
                        cnt--;
                    i++;
               } 
            }
            
            j++;
        }
        
        if(ans==-1e9)   return n;
        return ans;
    }
};
