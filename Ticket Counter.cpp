class Solution {

  public:

    int distributeTicket(int N, int K) {

        // code here

        int start = 1;

        int end = N;

        bool flag = true;

        while(end-start+1>K)

        {

            start += K;

            flag = false;

            if(end-start+1>K) 

            {

                flag = true;

                end -= K;

            }

        }

        if(flag) return end;

        return start;

    }

};
