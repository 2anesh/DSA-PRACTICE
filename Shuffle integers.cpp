class Solution{
 
 
 
public:
void shuffleArray(int arr[],int n)
{
         int mx=*max_element(arr,arr+n);
         
         for(int i=0;i<n;i++){
             arr[i]*=(mx+1);
         }
         int i=0,j=0;
           while(i < n){
               int num=arr[j]/(mx+1);
                       arr[i]=arr[i]+num;
                       i=i+2;
                       j++;
           }
           
         j=n/2;i=1;
         while(i < n){
             int num=arr[j]/(mx+1);
                     arr[i]=arr[i]+num;
                     j++;
                     i=i+2;
         }
         for(int i=0;i<n;i++){
             arr[i]%=(mx+1);
         }
}
 
 
};
