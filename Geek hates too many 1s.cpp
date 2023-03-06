class Solution {

  public:
    int noConseBits(int n) {
       int arr[32]={0};

         int x=n;

         int i=0;

         while(x){

             if(x&1){

                 arr[i]=1;

             }

             i++;

             x=x/2;

         }

        

        i=31;

        while(i>=2){

            if(arr[i-1]==1 && arr[i-2]==1 && arr[i]==1){

                arr[i-2]=0;

                i-=3;

            }else{

                i--;

            }

        }

         

         int ans=0;

         

         int k=1;

         for(int i=0;i<32;i++){

             if(arr[i]==1)

                ans+=(k);

                k*=2;

         }

         return ans; // code here
    }
};
