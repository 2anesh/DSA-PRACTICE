class Solution  {
    static long solve(int n, int k, ArrayList<Long> list)  {
        long sum = 0;
        for(long l: list) sum += l;
        
        for(int curr=k; curr<n; curr++)  {
            list.add(sum);
            sum = sum + list.get(curr) - list.get(curr-k);
        }
        return list.get(n-1);
    }}
