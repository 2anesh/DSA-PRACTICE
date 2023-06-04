class Solution
{
   
    String reverseEqn(String S)
    {
        // your code here
        StringBuilder reverseString=new StringBuilder();
        int firstDigit=-1;
        for(int i=S.length()-1;i>=0;i--)
        {
            //System.out.println("Character at Index:: "+i+", is:: "+S.charAt(i));
            if(S.charAt(i)>='0' && S.charAt(i)<='9')
            {
                //System.out.println("In Number Condition");
                if(i>0 && S.charAt(i-1)>='0' && S.charAt(i-1)<='9')
                {
                    //System.out.println("In Next Number Condition");
                    firstDigit=i+1;
                    continue;
                }
                else
                {
                    //System.out.println("In Single Number Condition");
                    if(firstDigit>0)
                    {
                        reverseString.append(S.substring(i,firstDigit));
                        firstDigit=-1;
                    }
                    else
                    {
                        reverseString.append(S.charAt(i));
                    }
                }
            }
            else
            {
                //System.out.println("In Operator Condition");
                if(firstDigit>0)
                {
                    reverseString.append(S.substring(i,firstDigit));
                }
                firstDigit=-1;
                reverseString.append(S.charAt(i));
            }
        }
        return reverseString.toString();
    }
}
