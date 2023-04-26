class Solution {
    public static boolean is_possible_to_get_seats(int n, int m, int[] arr) {
        // code here
        int prev = -10;
        int ans =0;
        if(n==0){
            return true;
        }
        if(m==1){
            
            if(arr[0] == 0){
                return true;
            }else{
                return false;
            }
            
        }
        for(int i = 0 ; i < m-1 ; i++){
            if(arr[i] == 1){
                prev = i;
            }else if(arr[i] == 0 && arr[i+1] != 1 && prev < i-1){
                ans++;
                arr[i] = 1;
                prev = i;
                if(ans == n){
                    return true;
                    
                }
            }
        }
        if(arr[m-1] == 0 && arr[m-2] == 0 ){
            arr[m-1] = 1;
            ans++;
        }
        if(ans == n){
            return true;
        }else{
            return false;
        }
    }
}
