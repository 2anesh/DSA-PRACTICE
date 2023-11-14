class Solution {
    public int countPalindromicSubsequence(String s) {
        Set<String> Palindrom = new HashSet<>();
        Set<Character> left = new HashSet<>();
        Map<Character,Integer> right = new HashMap<>();
        left.add(s.charAt(0));


        for (int i = 1; i < s.length(); i++) {
            if (right.containsKey(s.charAt(i))){
                right.put(s.charAt(i),right.get(s.charAt(i))+1);

            }else {
                right.put(s.charAt(i),1);
            }

        }

        for (int i = 1; i < s.length()-1; i++) {
            char mid = s.charAt(i);
            left.forEach( (x) -> {
                if(right.containsKey(x)) {
                    if(!((x == mid ) && (right.get(mid) == 1))){
                        Palindrom.add(""+x+mid+x);
                    }
                }
            });
            left.add(mid);
            if (right.get(mid) > 1) {
                right.put(mid, right.get(mid)-1);
            }else right.remove(mid);
        }

        return Palindrom.size();
    }
}
