class Solution {
public:
    int helper(vector<int>&nums1,vector<int>&nums2,int i ,int j,vector<vector<int>>&dp){
        if(i>=nums1.size() || j>=nums2.size()){
            return 0;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int poss1=0;
        int poss2=0;
        if(nums1[i]==nums2[j]){
            poss1=1+helper(nums1,nums2,i+1,j+1,dp);
        }
        else{
            int temp1=helper(nums1,nums2,i+1,j,dp);
            int temp2=helper(nums1,nums2,i,j+1,dp);
            poss2=max(temp1,temp2);
        }

        return dp[i][j]=max(poss1,poss2);
        
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));

        vector<int>curr(n2+1,0);
        vector<int>next(n2+1,0);
        for(int i=n1-1;i>=0;i--){
            for(int j=n2-1;j>=0;j--){
                

                    int poss1=0;
                    int poss2=0;
                    if(nums1[i]==nums2[j]){
                        poss1=1+next[j+1];
                    }
                    else{
                        int temp1=next[j];
                        int temp2=curr[j+1];
                        poss2=max(temp1,temp2);
                    }

                curr[j]=max(poss1,poss2);
            }
            next=curr;
            
        }

        return curr[0];

        //return helper(nums1,nums2,0,0,dp);
        
    }
};
