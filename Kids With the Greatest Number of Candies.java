class Solution {
    public List<Boolean> kidsWithCandies(int[] candies, int extraCandies) {
        boolean res=false;
        int n=candies.length;
        ArrayList <Boolean> result=new ArrayList<Boolean>();
        for(int i=0;i<candies.length;i++)
        {
              int sum=0;
            sum=candies[i]+extraCandies;
            res=max(sum,candies);
           result.add(res);
        }
        return result;
    }
    
    boolean max(int sum,int[] candies)
    {
        for(int i=0;i<candies.length;i++)
        {
            if(candies[i]<=sum)
                continue;
            else
                return false;
                }
        return true;
    }
}
