class Solution {
    public static ArrayList<Integer> makeBeautiful(int[] arr) {
        // code here
        Stack<Integer> s = new Stack<>();
        for(int i =0; i<arr.length;i++ ){
            if(s.empty()) {
                //enter first element is 
                s.push(arr[i]);
                continue;
            }
            //check top ele of stack and arr[i] sign opposite or not
            //if opposite then remove top ele according to Q.
            if((s.peek()^arr[i])<0) s.pop();
            //if sign is same then add ele;
            else{
                s.push(arr[i]);
            }
        }
          //move stack to ArrayList and return list
          ArrayList<Integer> list = new  ArrayList<Integer>(s);
         return list;
    }
}
