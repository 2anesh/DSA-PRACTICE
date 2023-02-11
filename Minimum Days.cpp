class Solution {

  public:

    int getMinimumDays(int N,string A, vector<int> &P) {

        int days=0;

        for(int i=0;i<N;i++){

            int tar=P[i];

            if( (tar+1<N && A[tar]==A[tar+1] && A[tar]!='?' ) || (tar-1>=0 && A[tar-1]==A[tar] && A[tar]!='?') ){

                days = i+1;

                A[tar]='?';

            } 

        }

        return days;

    }

};
