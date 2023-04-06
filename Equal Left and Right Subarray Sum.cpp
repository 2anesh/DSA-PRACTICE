int equalSum(int N, vector<int> &A) {
        // code here
        long long ls=0,rs=0,ans=-1,i=0;
        int s=0,e=N-1;
        while(s<=e){
            if(ls==rs && i<N-1){
                ls+=A[s++];
                rs+=A[e--];
                i+=2;
            }
            else if(ls>rs) rs+=A[e--],i++;
            else if(ls<rs) ls+=A[s++],i++;
            else if(ls==rs && i==N-1){
                ans=s+1;
                break;
            }
            
        }
       
       return ans;
    }
