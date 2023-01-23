class Solution {

    public static String removePair(String s) {

        // code here

        if(s.length()==0){

            return "-1";

        }

        Stack <Character> st=new Stack<>();

        String S="";

        for (int i=s.length()-1;i>=0;i--){

            if(st.isEmpty()){

                char ch=s.charAt(i);

                st.add(ch);

            }

            else if(st.peek()==s.charAt(i)){

                st.pop();

            }

            else {

                char ch=s.charAt(i);

                st.add(ch);

            }

        }

        if(st.isEmpty()) return "-1";

        while(!st.isEmpty()){

            S=S+String.valueOf(st.peek());

            st.pop();

        }

        return S;

    }

}
