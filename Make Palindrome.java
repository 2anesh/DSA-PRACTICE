class Solution {
    public static boolean makePalindrome(int n, String[] arr) {
        // code here
        int count = 0;
        
        String k[] = new String[n];
        for(int i=0;i<n;i++){
            StringBuilder sb = new StringBuilder(arr[i]);
            k[i] =  sb.reverse().toString();
         }
        Arrays.sort(arr);
        Arrays.sort(k);
        
     for(int i=0;i<n;i++){
            if(arr[i].equals(k[i])){
              count++;  
            }
       }
        if(count ==n)
        return true;
        
    return false;}
}
