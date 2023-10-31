class Solution {
    public int[] findArray(int[] pref) {
        int[] ans=new int[pref.length];
        ans[0]=pref[0];
        int ansXor=0;
        int prefXor=0;
        for(int i=1;i<pref.length;i++){
            
            ansXor^=ans[i-1];
            prefXor=ansXor ^ pref[i];
            ans[i]=prefXor;
        }    
        return ans;
    }
}
