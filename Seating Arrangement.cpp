class Solution{
    public:
    bool is_possible_to_get_seats(int n, int m, vector<int>& seats){
        // Write your code here.
    vector<int>vis(m,0); 
    for(int i =0 ;i<m;i++){
        if( seats[i]==1){
            if( i!=0){
                vis[i-1]=1;
            }
            if( i!= m-1){
                vis [i+1]=1;
            }
            vis[i]=1;
        }
        
    }
    int s =0;
    int ans =0;
 for(int i= 0;i<m;i++){
     if(vis[i]==0){
         s++;
     }
     else{
         if(s%2==0){
             ans+= s/2;
         }
         else{
             ans+= s/2 +1;
         }
         s=0;
     }
 }
 if(s>=1){
     if(s%2==0){
             ans+= s/2;
         }
         else{
             ans+= s/2 +1;
         }
 }
 return ans>=n;
    }
};

