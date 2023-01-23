class Solution {
    public int findJudge(int n, int[][] trust) {
       int [][]isVisited=new int[n+1][n+1];
        ArrayList<Integer> al=new ArrayList<>();
        for(int i=1;i<=n;i++){
            al.add(i);
        }
        
        for(int[] a:trust){
            isVisited[a[0]][a[1]]=1;
            if(al.contains(a[0])){
               int index=al.indexOf(a[0]);
               al.remove(index); 
            }
            
        }
        if(al.size()!=1){
            return -1;
        }
        
        int res=al.get(0);
        for(int i=1;i<=n;i++){
            if(i!=res){
                if(isVisited[i][res]!=1){
                    return -1;
                }
            }
        }
        return res;
    }
}
