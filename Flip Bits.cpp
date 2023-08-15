class Solution{
    public:
    
    int findones(int a[],int n)
    {
        int count=0;
        
        for(int i=0;i<n;i++)
        {
            if(a[i])
            {
                count++;
            }
        }
        
        //cout<<count<<"\n***";
        
        return count;
    }
    
    int maxOnes(int a[], int n)
    {
        // Your code goes here
        int maxcount=0,count=0;
        
        for(int i=0;i<n;i++)
        {
            if(a[i]==0)
            {
                count++;
            }
            else
            {
                count--;
            }
            
            //cout<<count<<"---"<<"\n";
            
            if(count>0 && maxcount<count)
            {//if count is positive amd more than maxcount then only update maxcount 
            //as these are the number of 0's extra than number of 1's .These 0's when flipped will give us more 1's
                maxcount=count;
            }
            else if(count<0)
            {//if count is < 0 means more 1's will be lost than 0's converted to 1's or if count is less than maxcount
                //we will get more 1's than 0's after flipping but but it will be less than previous index where are getting more 1's than 0's in flipping than flipping till here
                //so in short no need to touch the maxcount for second case only for 1st case as the difference(count) will be useful ahead also
                count=0;
            }
        }
        
      //  cout<<maxcount<<"\n";
        int g=findones(a,n);
      //  cout<<g<<"\n";
        return (maxcount+g);//maxcount is the extra number of 0's we are getting compared to 1's but the number of 0's==1's will be counted through this function's number of 1's count
    }
};
