class Solution {
    public int compress(char[] chars) {
        StringBuffer s = new StringBuffer();
        s.append(chars[0]);
        int count=1;
        for(int i=1;i<chars.length;i++){
            if(chars[i]==chars[i-1]){
                count++;
            }
            else{
                if(count>1){
                    s.append(count);
                    count=1;
                }
                s.append(chars[i]);
            }
        }
        if(count>1){
            s.append(count);
        }
        int n = chars.length;
        String t = s.toString();
        char[] a = t.toCharArray();
        for(int i=0;i<a.length;i++){
            chars[i] = a[i];
        }
        return a.length;
    }
}
