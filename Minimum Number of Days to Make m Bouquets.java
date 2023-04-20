class Solution {
    public int minDays(int[] bloomDay, int m, int k) {
        int ans = -1;
        
        //Minimum required no of days will be min of the array
        //Maximum required no of days will be max of the array
        
        int low = Arrays.stream(bloomDay).min().getAsInt();
        int high = Arrays.stream(bloomDay).max().getAsInt();
        
        // Apply Binary Search on days
        while(low <= high)
        {
            int mid = low + (high - low)/2;
            
        
            // If current no of days is answer, check for lesser answer by decreasing high to mid - 1 
            // else increase low to mid + 1
            if(isPossible(bloomDay, m, k, mid))
            {
                ans = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        
        return ans;
    }
    
    
    boolean isPossible(int[] bloomDay, int noOfBouquets, int flowersRequired, int days)
    {
        int currFlowersCount = 0, bouquetsDone = 0;
        
        for(int day : bloomDay)
        {
            if(day <= days)
            {
                currFlowersCount++;
                // If currFlowersCount is equal to K, increase BouquetsDone and 
                // make currFlowersCount equal to zero
                if(currFlowersCount == flowersRequired)
                {
                    bouquetsDone++;
                    currFlowersCount = 0;
                    if(bouquetsDone == noOfBouquets)
                        return true;
                }
            }
            else
                currFlowersCount = 0; // only adjacent flowers must be used to make bouquets
        }
        
        return false;
    }
}
