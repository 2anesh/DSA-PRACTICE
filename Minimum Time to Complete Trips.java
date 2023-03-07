class Solution {

public long solve(int[] time , long m)
{
    long cal=0;
    for(int val:time)
    {
    
        cal+=(m/val);
    }
    return cal;
}
public long minimumTime(int[] time, long totalTrips) {
    
    
    long sum=0;
    for(int val:time) sum+=val;
        
    
    long l=0;
    long h=sum*totalTrips;
    long ans=h;
    while(l<=h)
    {
        long m=l+(h-l)/2;
       if(solve(time,m)>=totalTrips)
        {
           ans=m;
            h=m-1;
        }
        else
        {
           l=m+1;
        }
    }
    return ans;
}
}
