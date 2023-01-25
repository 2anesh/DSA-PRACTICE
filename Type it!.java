class Solution {

    int minOperation(String s) 

    {

        int ans=find(s,"",0,true);

        

        return ans;

    }

    public static int find(String s,String upto,int i,boolean flag)

    {

        if(upto.equals(s))

        {

        return 0;

        }

        

        if(upto.length()>s.length()||i>=s.length())

        return 9999;

        

        if(flag)

        {

            int pick=find(s,upto+""+upto,i+upto.length(),!flag);

            

            int notpick=find(s,upto+s.charAt(i),i+1,flag);

            

            return 1+Math.min(pick,notpick);

        }

        else

        return 1+find(s,upto+s.charAt(i),i+1,flag);

    }

}
