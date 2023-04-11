class Solution {
    public String removeStars(String s) {
        s=s.trim();

        StringBuilder sb=new StringBuilder();
        for(int i=0;i<s.length();i++){
            if(s.charAt(i)!='*'){
              sb.append(s.charAt(i));
            }
            else{
                sb.deleteCharAt(sb.length()-1);
            }
        }
        return sb.toString();
    }
}
