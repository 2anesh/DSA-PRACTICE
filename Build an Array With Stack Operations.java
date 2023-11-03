class Solution {
    public List<String> buildArray(int[] target, int n) {
        Stack<Integer> stack = new Stack<>();
        List<String> res = new ArrayList<>();
        int i=0, c=1;
        while(true){

                stack.push(c);
                res.add("Push");
                c++;

            if(stack.peek()==target[i]){
                i++;
            }
            else{
                stack.pop();
                res.add("Pop");
            }
            if(i==target.length)
                break;
        }
        return res;
    }
}
