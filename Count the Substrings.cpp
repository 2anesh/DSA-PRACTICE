int countSubstring(string S)
    {
        // code here
        int lower = 0,upper = 0,count = 0;
        for(int i = 0;i < S.length();i++){
            for(int j = i;j < S.length();j++){
                if(islower(S[j]))
                lower++;
                else if(isupper(S[j]))
                upper++;
                
                if(lower == upper)
                count++;
            }
            lower = 0;
            upper = 0;
        }
        
        return count;
    }
