class Solution {
    public boolean winnerOfGame(String colors) {
        int alice=0,bob=0;
        if(colors.length()<3)
        return false;
        else
        {
            for(int i=1;i<colors.length()-1;i++)
            {
                if((colors.charAt(i-1)==colors.charAt(i)) && (colors.charAt(i)==colors.charAt(i+1))){
                if(colors.charAt(i)=='A')
                alice++;
                else
                bob++;
                }
            }
        }
        return alice>bob;
    }
}
