
class Solution{

    public int maxWeightCell(int N, int Edge[]){

       

       int res[]=new int[N];

       for(int i=0;i<N;i++){

           if(Edge[i]!=-1)res[Edge[i]]+=i;

       }

       

       

       int max=0;

       for(int i=0;i<N;i++){

           max=Math.max(max,res[i]);

       }

       

       for(int i=N-1;i>=0;i--){

           if(res[i]==max)return i;

       }

       return 0;

    }

 

}

