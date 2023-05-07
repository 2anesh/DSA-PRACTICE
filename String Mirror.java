class Solution {
    public static String stringMirror(String str) {
        // code here
        StringBuilder s=new StringBuilder();
        s.append(str.charAt(0));
        
        for(int i=1;i<str.length();i++)
        {
            if(str.charAt(i)<str.charAt(i-1))
            s.append(str.charAt(i));
            else if(str.charAt(i)>str.charAt(i-1))
            break;
            else if(str.charAt(i)==s.charAt(0))
            break;
            else
            s.append(str.charAt(i));
        }
        StringBuilder rev=new StringBuilder(s);
        rev.reverse();
        String res=s.toString()+rev.toString();
        return res;
    }
}
