class Solution {
  public:
    int bitMagic(int n, vector<int> &arr) {
        // code here
        int i = 0 , j = n-1;
        int cnt = 0;
        
        while(i < j) {
            if(arr[i] != arr[j]) {
                cnt++;
            }
            i++;
            j--;
        }
        return cnt % 2 == 0 ? cnt/2 : cnt/2+1;
    }
};
