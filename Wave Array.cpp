class Solution{
    public:
    
    void convertToWave(int n, vector<int>& arr){
      int i=0;
      while(i+1<n)
      {
          int temp=arr[i];
          arr[i]=arr[i+1];
          arr[i+1]=temp;
          i+=2;
      }
    }
};
