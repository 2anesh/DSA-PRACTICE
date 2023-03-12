class Solution {
    public int nextGreaterElement(int n) {
        String str = String.valueOf(n);
        char [] arr = str.toCharArray();
        
        int i = arr.length - 2;
        
        while(i>=0 && arr[i]>=arr[i+1]){
            i--;
        }
        
        if(i == -1)
            return -1;
        
        //find just greater element than ith element
        int k = arr.length - 1;
        while(arr[i] >= arr[k]){
            k--;
        }
        
        // swap i and k th element
        char temp = arr[i];
        arr[i] = arr[k];
        arr[k] = temp;
        
        //concatenate from 0 to ith index
        
        String result = "";
        for(int j=0; j<=i; j++){
            result+=arr[j];
        }
        
        //concatenate from end of arr to i in reverse order
        
        for(int j=arr.length-1;j>i;j--){
            result+=arr[j];
        }
        if(Long.parseLong(result) > 2147483647){
            return -1;
        }
        return Integer.parseInt(result);
    }
}
