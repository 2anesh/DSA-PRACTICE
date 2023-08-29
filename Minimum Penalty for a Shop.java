class Solution {
    public int bestClosingTime(String customers) {
        
        int n = customers.length();
        int [] arr1 = new int[n];
        int [] arr2 = new int[n];
        char[]ca = customers.toCharArray();
        
        if(ca[0]=='N')
            arr2[0]++;
        
        for(int i=1;i<n;i++)
        {
            if(ca[i]=='N')arr2[i]++;arr2[i]+=arr2[i-1];
        }
        
        if(ca[n-1]=='Y')arr1[n-1]++;
        
        for(int i=n-2;i>=0;i--)
        {
             if(ca[i]=='Y')arr1[i]++;arr1[i]+=arr1[i+1];
        }
        
        int marks = 10000000;
        int ind = -1;
        for(int i=0;i<n;i++)
        {
            int curr = arr1[i];int prev = 0;
            if(i-1>=0)prev = arr2[i-1];curr +=prev;
            if(curr<marks)
            {
                marks = curr;
                ind = i;
            }
        }

        int lastt = arr2[n-1];
        if(lastt<marks)return n;
        return ind;
        
    }
}
