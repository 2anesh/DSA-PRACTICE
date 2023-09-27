class Solution {
    public String decodeAtIndex(String s, int k) {
       long size=0;
       int n=s.length();
       for(char c : s.toCharArray()){
         if(Character.isDigit(c)){
           size=size*(c-'0');
         }
         else{
           size++;
         }
       }
       for(int i=n-1;i>=0;i--){
         char c=s.charAt(i);
         k%=size;
         if((k==0 || k==size) && Character.isLetter(c)){
           return Character.toString(c);
         }
         if(Character.isDigit(c)){
           size=size/(c-'0');
         }
         else
         {
           size--;
         }
       }
       return null;  
    }
}
