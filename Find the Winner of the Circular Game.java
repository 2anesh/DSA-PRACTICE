class Solution {
    public int findTheWinner(int n, int k) {
       Queue<Integer> q= new LinkedList<>();
        for(int i=1;i<=n;i++){
            q.add(i);
        }
        int r=1;
        while(q.size()!=1){
            int curr=q.remove();
            if(r%k!=0){
                q.add(curr);
            }
            r++;
        }
        
        return q.remove();
    }
}
