class Solution
{
    int kSubstrConcat(int n, String s, int k)
    {
        HashMap<String,Integer> m=new HashMap<>();
        if(n%k>0)
        return 0;
        for(int i=0;i<=n-k;i=i+k)
        {
            String r=s.substring(i,i+k);
            if(!m.containsKey(r))
            m.put(r,1);
            else
            m.put(r,m.get(r)+1);
        }
        return (m.size()<=2)?1:0;
        
    }
}
