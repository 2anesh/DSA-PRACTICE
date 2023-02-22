class Solution {
public:
    bool check(int mid, vector<int> w, int days, int n){
        int cnt = 0, temp = 0;
        for(int i=0; i<n; i++){
            temp = temp + w[i];
            if(temp > mid){
                cnt++;
                temp = w[i];
            }
        }
        if(cnt >= days){
            return true;
        }else{
            return false;
        }
    }
    int shipWithinDays(vector<int>& w, int days) {
        int n = w.size();
        int low=0,high=0;
        for(int i=0; i<n; i++){
            low = max(low,w[i]);
            high = high + w[i];
        }
        
        int mid,ans;
        while(low <= high){
            mid = low + (high-low)/2;
            if(!check(mid,w,days,n)){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};
