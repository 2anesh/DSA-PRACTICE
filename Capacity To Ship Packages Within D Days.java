class Solution {
    public static boolean isPossible(int[] weights, int days, int mid){
        int dayCount = 1;
        int weightSum = 0;

        for(int i=0; i<weights.length; i++){
            if(weights[i] + weightSum <= mid){
                weightSum += weights[i];
            }
            else{
                dayCount++;
                weightSum = 0;

                if(weights[i] > mid || dayCount > days){
                    return false;
                }

                weightSum += weights[i];
            }
        }

        return true;
    }

    public int shipWithinDays(int[] weights, int days) {
        int sum = 0;
        for(int i=0; i<weights.length; i++){
            sum += weights[i];
        }

        int s = 0;
        int e = sum;
        int mid = s + (e-s)/2;
        int ans = 0;

        while(s<=e){
            if(isPossible(weights,days,mid)){
                ans = mid;
                e = mid-1;
            }
            else{
                s = mid+1;
            }
            mid = s + (e-s)/2;
        }

        return ans;
    }
}
