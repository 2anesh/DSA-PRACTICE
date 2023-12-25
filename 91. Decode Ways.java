class Solution {
    public int numDecodings(String s) {
        Map<Integer,Integer> memo = new HashMap<>();
        return recursion(memo,s,0);        
    }
    public int recursion(Map<Integer,Integer> memo,String s,int first){        
        if(first==s.length() ){
            return 1;
        }
        if(s.charAt(first)=='0'){
            return 0;
        }
        if(first == s.length()-1){
            return 1;
        } 
        if(memo.containsKey(first)){
            return memo.get(first);
        }
        int count = recursion(memo,s,first+1); 
        int twodigits=Integer.parseInt(s.substring(first,first+2));
        if(twodigits<=26){
            count+=recursion(memo,s,first+2);
        }
        memo.put(first,count);
        return count;
    }
}
