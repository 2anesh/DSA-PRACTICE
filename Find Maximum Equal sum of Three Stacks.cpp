class Solution{
public:
    int maxEqualSum(int n1,int n2,int n3,vector<int> &s1,vector<int> &s2,vector<int> &s3){
        int suff1=0,suff2=0,suff3=0;
        int i=n1-1,j=n2-1,k=n3-1;
        bool f1=1,f2=1,f3=1;
        int ans = 0;
        while(i>=0 && j>=0 && k>=0)
        {
            if(f1)
                suff1+=s1[i];
            if(f2)
                suff2+=s2[j];
            if(f3)
                suff3+=s3[k];
            
            if(suff1 == suff2 && suff2 == suff3)
            {
                ans = max(ans,suff1);
                f1=1,f2=1,f3=1;
                i--,j--,k--;
                continue;
            }
            f1=0,f2=0,f3=0;
            int maxe = max({suff1,suff2,suff3});
            if(maxe>suff1){
                i--;
                f1=1;
            }
            if(maxe>suff2){
                j--;
                f2=1;
            }
            if(maxe>suff3){
                k--;
                f3=1;
            }
        }
        if(suff1 == suff2 && suff2 == suff3)
        {
            ans = max(ans,suff1);
        }
        return ans;
    }
};
