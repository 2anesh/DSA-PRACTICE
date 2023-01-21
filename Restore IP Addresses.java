class Solution {
    List<String> list = new ArrayList<>();
    public List<String> restoreIpAddresses(String s) {
        recursion(s, "", 0, 4);
        System.out.println(list);
        return list;
    }
    void recursion(String s, String str, int i, int k){
        if(i == s.length() && k == 0){
            list.add(str.substring(0,str.length()-1));
            return;
        }
         
        for(int x = i; x < Math.min(s.length(),i+3); x++){
            if(k < 0) break;
            String sb = s.substring(i,x+1);
            int num = Integer.parseInt(sb);
            int size = sb.length();
            if(size == 2 && num < 10) continue;
            if(size == 3 && num < 100) continue;
            if(size == 3 && num > 255) continue;
            recursion(s, str + sb + ".", x+1, k-1);
        }
    }
    
}
