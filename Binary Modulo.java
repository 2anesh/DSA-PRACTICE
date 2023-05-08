class Solution{
    int modulo(String s, int m) {
        int len = s.length();
        int ans = 0;
        int x = 1;
        for(int i = len- 1;i>=0; i--){
            if(s.charAt(i) =='1' ){
                ans = (ans +x)%m ;
            }
            x = x*2;
            x %=m;
         }
         return ans;
    }
}
