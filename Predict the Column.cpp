class Solution{
    public:
    int columnWithMaxZeros(vector<vector<int>>arr,int N){

          int large=0, index=-1;

        for(int i=0;i<N;i++){

               int count1=0,count2=-1;

            for(int j=0;j<N;j++){

                if(arr[j][i]==0){

                    count1++;

                    count2=i;

                }

                if(count1>large){

                    large=count1;

                    index=i;

                }

            }

        }
        return index;
    }
};
