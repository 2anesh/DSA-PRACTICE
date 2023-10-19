class Solution {
    public boolean backspaceCompare(String s, String t) {

        Stack<Character> res=new Stack<>();
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c == '#' && !res.isEmpty()) {
                res.pop();
            } else if (c != '#') {
                res.push(c);
            }
        }

        Stack<Character> res2=new Stack<>();
        for (int i = 0; i < t.length(); i++) {
            char c = t.charAt(i);
            if (c == '#' && !res2.isEmpty()) {
                res2.pop();
            } else if (c != '#') {
                res2.push(c);
            }
        }

       if(res.size()!=res2.size())
        return false;

        while (!res.isEmpty()) {
            if (res.pop() != res2.pop()) {
                return false;
            }
        }
        return true;
    }
}
