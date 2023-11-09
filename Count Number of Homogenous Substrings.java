class Solution {
    public int countHomogenous(String s) {
        long count =1;
        long max = 0;
        for(int i=1;i<s.length();i++)
        {
            if(s.charAt(i)==s.charAt(i-1))
            count++;
            else
            {
                max = max+(count*(count+1)/2);
                count =1;
            }
        }
        if(count>=1)
        max = max+(count*(count+1))/2;
        return (int)(max%(Math.pow(10,9)+7));
    }
}
