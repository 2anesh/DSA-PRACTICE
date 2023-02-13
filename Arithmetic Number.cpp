class Solution{

public:

    int inSequence(int A, int B, int C)

    {

        if(A==B)

        {

            return 1;

        }

        

        if(B!=A && C==0)

        {

            return 0;

        }

        

        int num=B-A;

        if(num<0)

        {

            if(C<0 && num%C==0)

            {

                return 1;

            }

        }

        else

        {

            if(C>0 && num%C==0)

            {

                return 1;

            }

        }

        return 0;

    }

};

