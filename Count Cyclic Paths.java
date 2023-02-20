class Solution{

 public static int countPaths(int N){

 //code here

 int m = 1000000007;

 long ans = 0;

 for(int i=2;i<=N;i++){

     if(i%2==0){

         ans=(ans%m*3%m)%m+3;

     }else{

         ans=(ans%m*3%m)%m-3;

     }

 }

 return (int)ans%m;

 }

}
