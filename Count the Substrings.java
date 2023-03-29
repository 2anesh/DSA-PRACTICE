class Solution 
{ 
    int countSubstring(String S) 
    { 
        // code here
        HashMap<Integer,Integer> map = new HashMap<>();
        map.put(0,1);
        int sum=0,ans=0;
        for(int i=0;i<S.length();i++) {
            if(S.charAt(i)>='A' && S.charAt(i)<='Z') {
                sum++;
            } else {
                sum--;
            }
            
            if(map.containsKey(sum)) {
                ans+=map.get(sum);
                map.put(sum,map.get(sum)+1);
            } else {
                map.put(sum,1);
            }
        }
        return ans;
    }
} 
