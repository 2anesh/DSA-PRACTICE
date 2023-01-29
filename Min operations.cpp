class Solution {

  public:

    int solve(int a, int b) {

        // code here

        int i,c=0,d=0;

        if(a == b)

        return 0;

        

        else

        {

           for(i=31;i>=0;i--)

           {

               if(!(a&(1<<i)))

               {

                   if(b&(1<<i))

                   {

                       c++;

                       break;

                   }

               }

           }

           

            for(i=31;i>=0;i--)

           {

               if(!(b&(1<<i)))

               {

                   if(a&(1<<i))

                   {

                       d++;

                       break;

                   }

               }

           }

           if(c>0 && d>0)

           return 2;

           else

           return 1;

           

        }

    

    }

};   

