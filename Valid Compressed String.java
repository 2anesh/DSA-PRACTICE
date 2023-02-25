static int checkCompressed(String S, String T) {
        // code here
        
        int i=0,j=0;
        while(j<T.length()){
            if(Character.isLetter(T.charAt(j))){
                if(i>=S.length() || T.charAt(j)!=S.charAt(i)){
                    return 0;
                }
                i++;
                
            }else{
                int count = Character.getNumericValue(T.charAt(j));
                while(j+1<T.length() && Character.isDigit(T.charAt(j+1))){
                    count = count*10+Character.getNumericValue(T.charAt(j+1));
                    j++;
                }
                if(count>S.length()-i){
                    return 0;
                }
                i=i+count;
            }
            j++;
        }
        
        if(i==S.length()){
            return 1;
        }else return 0;
        
    }
