class Solution{   
public:
    long long int distinctColoring(int n, int r[], int g[], int b[]){
        // code here 
        vector<long long int>red(n,0);
        vector<long long int>green(n,0);
        vector<long long int>black(n,0);
        for(int i=0;i<n;i++){
            if(i==0){
                red[i]=r[i];
                green[i]=g[i];
                black[i]=b[i];
            }else{
                red[i]=min(r[i]+black[i-1],r[i]+green[i-1]);
                green[i]=min(g[i]+black[i-1],g[i]+red[i-1]);
                black[i]=min(b[i]+red[i-1],b[i]+green[i-1]);
            }
        }
        return min(green[n-1],min(red[n-1],black[n-1]));
    }
};
