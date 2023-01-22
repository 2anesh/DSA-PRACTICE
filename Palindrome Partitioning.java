class Solution {
    public boolean isPalindrome(String s){
        int i = 0, j = s.length()-1;

        while(i < j){
            if(s.charAt(i)!=s.charAt(j)){
                return false;
            }
            i++;
            j--;
        }

        return true;
    }

    public void helper(int idx, String s, String tempStr, List<List<String>> res, List<String> ls ){
        if(idx == s.length()) {
            res.add(new ArrayList<>(ls));
            return;
        }

        tempStr = "";
        
        for(int i = idx; i<s.length(); i++){
            tempStr += ""+s.charAt(i);
            if(isPalindrome(tempStr)){
                ls.add(tempStr);
                helper(i+1, s, "", res, ls);
                ls.remove(ls.size()-1);
            }
        }
    }

    public List<List<String>> partition(String s) {
        List<List<String>> res = new ArrayList<>();
        helper(0, s , "", res, new ArrayList<>());
        return res;
    }
}
