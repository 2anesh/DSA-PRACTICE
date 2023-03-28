static long find(int n, long k){
        // Return the number of chocolates Geek had
        // enjoyed out of 'n' chocolates availabe in the
        // 'shop'.
        
        long ans=0;
        HashMap<Integer,Integer> map = new HashMap<>();
        while(k>0) {
            long value = search(k,n,map);
            if(value==-1) break;
            ans+=(k/value);
            k%=value;
        }
        return ans;
    }
    
    public static int search(long val,int n,HashMap<Integer,Integer> map) {
        int lo=0,hi=n-1;
        int ans=-1;
        while(lo<=hi) {
            int mid = lo+(hi-lo)/2;
            int cost;
            if(map.get(mid)==null) {
                 cost = shop.get(mid);
                 map.put(mid,cost);
            } else {
                 cost=map.get(mid);
            }
            
            if(cost==-1) return -1;
            
            if(cost<val) {
                ans=cost;
                lo=mid+1;
            } else if(cost>val) {
                hi=mid-1;
            } else {
                return cost;
            }
        }
        return ans;
    }
