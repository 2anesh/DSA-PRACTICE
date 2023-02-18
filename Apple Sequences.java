public static int appleSequence(int n, int m, String arr){
        int orangeCount = 0;
        int start = 0;
        
        int maxLen = Integer.MIN_VALUE;
        
        for(int i=0; i<n; i++){
            if(arr.charAt(i) == 'O') orangeCount++;
            while(orangeCount > m){
                if(arr.charAt(start) == 'O') orangeCount--;
                start++;
            }
            maxLen = Math.max(maxLen, i-start+1);
        }
        return maxLen;
    }
