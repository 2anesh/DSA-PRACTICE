class Solution {
    public String addStrings(String num1, String num2) {
         char [] longString = num1.length() >= num2.length() ? num1.toCharArray() : num2.toCharArray();
        char [] smallString = num1.length() <= num2.length() ? num1.toCharArray() : num2.toCharArray();
        smallString = num1.length() == num2.length() ? num2.toCharArray() : smallString;
        int j = smallString.length;
        StringBuilder stringBuilder = new StringBuilder();

        int carry = 0;
        for(int i = longString.length - 1; i >=0; i--) {
            int temp1 = Integer.parseInt(String.valueOf(longString[i]));
            //System.out.println("Temp1 " + temp1);
            int temp2 = 0;
            if(j > 0 ) {
                temp2 =  Integer.parseInt(String.valueOf(smallString[j - 1]));
                //System.out.println("Temp2 " + temp2);
                j --;
            }
            int sum = (temp1 + temp2 + carry ) % 10;
            //System.out.println("Sum " + sum);
            carry = (temp1 + temp2 + carry ) / 10;
            //System.out.println("carry " + carry);
            stringBuilder = stringBuilder.append(sum);
        }
        //System.out.println();
        if(carry > 0 ) {
            stringBuilder.append(carry);
        }
        return stringBuilder.reverse().toString();
    }
}
