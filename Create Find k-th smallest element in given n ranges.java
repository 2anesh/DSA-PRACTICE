class Solution {
    public static ArrayList<Integer> kthSmallestNum(int n, int[][] range, int q, int[] queries) {
        // code here
        ArrayList<Integer> ans=new ArrayList<>();
        Arrays.sort(range,new Comparator<int[]>() {
            public int compare(int a[],int b[]){
                return a[0]-b[0];
            }
        } );
        List<List<Integer>> list=new ArrayList<>();
        List<Integer> arr=new ArrayList<>();
        arr.add(range[0][0]);arr.add(range[0][1]);
        list.add(arr);
        for(int i=1;i<n;i++){
            if(list.get(list.size()-1).get(1)>=range[i][0]){
                list.get(list.size()-1).set(1,Math.max(list.get(list.size()-1).get(1),range[i][1]));
            }
            else{
                List<Integer> array=new ArrayList<>();
                array.add(range[i][0]);array.add(range[i][1]);
                list.add(array);
            }
        }
        for(int i=0;i<q;i++)
        {
            int ele=queries[i];
            boolean added=false;
            for(int j=0;j<list.size();j++){
                int window=list.get(j).get(1)-list.get(j).get(0)+1;
                if(window<ele){
                    ele=ele-window;
                }
                else{
                    added=true;
                    ans.add(list.get(j).get(0)+ele-1);
                    break;
                }
            }
            if(added==false){
                ans.add(-1);
            }
        }
        return ans;
    }
}
