class Solution
{private class pair implements Comparable<pair>
{
    int p,d;
    pair(int pp,int dd)
    {
        p=pp;d=dd;
    }
    public int compareTo(pair o)
    {
        return o.p-this.p;
    }
}
    //Function to find the maximum profit and the number of jobs done.
    int[] JobScheduling(Job arr[], int n)
    {
        // Your code here
        pair a[]=new pair[n];int t=0;int time=0;
        for(Job i:arr)
        {
            a[t++]=new pair(i.profit,i.deadline);
            time=Math.max(time,i.deadline);
        }Arrays.sort(a);int slot[]=new int[time+1];int pro=0,cnt=0;
        for(pair i:a)
        {
            if(slot[i.d]==0&& i.d!=0)
            {
                slot[i.d]=1;pro+=i.p;cnt+=1;
             
            }else{
                int temp=i.d;
                while(temp>0)
                {
                    if(slot[temp]==0)
                    {pro+=i.p;cnt+=1;
                        slot[temp]=1;break;
                    }temp--;
                }
               
            }
        }
        return new int[]{cnt,pro};
        
        
        
    }
}

