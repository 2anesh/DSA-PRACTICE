Long maxTripletProduct(Long arr[], int n)
    {
        // Complete the function
        long mx1=Integer.MIN_VALUE;
        long mx2=mx1,mx3=mx1;
        long mn1=Integer.MAX_VALUE;
        long mn2=mn1;
        for(long val : arr) {
            if(mx1<=val) {
                mx3=mx2;
                mx2=mx1;
                mx1=val;
            } else if(mx2<=val) {
                mx3=mx2;
                mx2=val;
            } else if(mx3<=val) {
                mx3=val;
            }
            
            if(mn1>=val) {
                mn2=mn1;
                mn1=val;
            } else if(mn2>=val) {
                mn2=val;
            }
        }
        return Math.max(mn1*mn2*mx1,mx1*mx2*mx3);
    }
