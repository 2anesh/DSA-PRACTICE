class Solution {
    public String largestGoodInteger(String num) {
        ArrayList<String> arr = new ArrayList<String>();
        for(int i=9;i>=0;i--)
        {
            String s = new String();
            for(int j=0;j<3;j++)
            {
                s=s+(char)(i+'0');
            }
            arr.add(s);
        }
        for(int i=0;i<=9;i++)
        {
            if(num.contains(arr.get(i)))
            return arr.get(i);
        }
        return "";
        }
}
