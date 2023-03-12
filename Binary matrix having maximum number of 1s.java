class Solution {

    public int[] findMaxRow(int mat[][], int N) {

        // code here

        int ans=Integer.MIN_VALUE;

       // int level=-1;

        int count=0;

        

        

        int result[]=new int[2];

        

        for(int i=0;i<mat.length;i++){

            count=0;

            int low=0;

            int high=mat[0].length-1;

            

            while(low<=high){

                int mid=(low+high)/2;

                

                if(mat[i][mid] == 1) high=mid-1;

                else low=mid+1;

            }

            count=N-low;

            if(ans<count){

                

                ans=count;

                result[0]=i;

                result[1]=count;

            }

        }

        

       

        

        return result;

    }

};
