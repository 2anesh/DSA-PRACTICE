class Solution {
public:
    int strStr(string haystack, string needle) {
        int k = 0; // changeable
        int h = 0; // changeable
        int index = 0; // changeable
        int needlelen  = needle.length();
        int n = needlelen;
        for(int i=0;i<haystack.length();i++){
            if(haystack[i] == needle[k]){
                if(k == 0){
                    index = i;
                    h = i;
                }
                while(needlelen){
                    if(haystack[h++] != needle[k++]){
                        break;
                    }
                    needlelen--;
                }
                if(needlelen == 0){
                    return index;   
                }
                needlelen = n;
                k=0;
            }
        }
        
        return -1;
    }
};
