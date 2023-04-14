class Solution {
    public static int finLength(int N, int[] color, int[] radius) {
        // code here
        Stack<Integer> st = new Stack<>();
        for(int i=0;i<N;i++){
            if(!st.isEmpty() && color[st.peek()]==color[i] && radius[st.peek()]==radius[i]){
                    st.pop();
                }
            else{
                st.push(i);
            }
        }
        return st.size();
    }
}
