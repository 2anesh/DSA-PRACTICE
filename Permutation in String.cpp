class Solution {
public:
    
    bool matches(int* s1,int* s2)
    {
        for (int i = 0; i < 26; i++) {
            if (s1[i] != s2[i])
                return false;
        }
        return true;
    }
    
    bool checkInclusion(string s1, string s2) {
        
        if (s1.length() > s2.length())
            return false;
        
        int size= s1.size();
        
        int s1Freq[26]={0};
        int s2Freq[26]={0};
        
        for(int i=0;i<size;i++)
        {
            s1Freq[s1[i] - 'a']++;
            s2Freq[s2[i] - 'a']++;
        }
            
        
        
        int i=0, j=size-1;
        
        while( j<= s2.size())
        {
            
            if( matches(s1Freq,s2Freq) )
                return true;
  
            if(j+1<s2.size())
            {
                s2Freq[s2[i++] - 'a']--;
                s2Freq[s2[++j] - 'a']++;
            }
            else
                return false;
            
        }
 
    return false;    
    }
};
