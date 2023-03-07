class Solution {
private:
    bool isPossible(long long mid,vector<int>& time, int totalTrips){
        long long cnt1=0;
        
        for(long long i=0;i<time.size();i++){
            cnt1+=(mid/time[i]);
        }
        
        if(cnt1>=totalTrips) return true;
        else return false;
    }
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        
        sort(time.begin(),time.end());
        long long sum=0;
        for(auto it:time) sum+=it;

        
        long long lo=1;
        long long hi=sum*totalTrips;
        long long ans=lo;
        
        while(lo<=hi){
            long long mid=lo+(hi-lo)/2;
    
            if(isPossible(mid,time,totalTrips)){
                ans=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }
        return ans;
    }
};
