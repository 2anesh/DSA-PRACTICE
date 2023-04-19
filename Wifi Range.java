class Solution 
{ 
    boolean wifiRange(int N, String S, int X) 
    { 
        // code here
        StringBuilder sb = new StringBuilder();
        sb.append(S);
        int i = 0;
        while(i<N){
            if(S.charAt(i) == '1'){
                int range = X;
                i++;
                while(i<N && range>0 && S.charAt(i) != '1'){
                    sb.setCharAt(i,'1');
                    i++;
                    range--;
                }
            }
            else
            i++;
        }
        i = N-1;
        while(i>=0){
            if(S.charAt(i) == '1'){
                int range = X;
                i--;
                while(i>=0 && range>0 && S.charAt(i) != '1'){
                    sb.setCharAt(i,'1');
                    i--;
                    range--;
                }
            }
            else
            i--;
        }
        if(sb.toString().contains("0"))
        return false;
        return true;
    }
} 
