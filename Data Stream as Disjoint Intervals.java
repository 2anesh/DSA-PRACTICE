class SummaryRanges {

    //same idea as merge sort
    List<int[]> data;
    
    //O1
    public SummaryRanges() {
        data = new ArrayList<>();
    }
    
    //O1 Lazy execution. As long as we keep track of the value being added we are fine and can process it later.
	//or we can try to merge here and maintain the result for faster output
    public void addNum(int val) {
        this.data.add(new int[]{val, val});        
    }
    
    //Onlogn to merge, On to copy
    public int[][] getIntervals() {
        List<int[]> res = merge(this.data);
        this.data = res;
        return res.toArray(new int[res.size()][2]);
    }
    
    //sort Onlogn, merge On
    private List<int[]> merge(List<int[]> intervals) {
        LinkedList<int[]> res = new LinkedList();
        Collections.sort(intervals, (a,b) ->(a[0]- b[0]));
        
        res.add(intervals.get(0));
        
        for(int i =1; i<intervals.size(); ++i){
            int[] interval = intervals.get(i);
            
            if(res.getLast()[1] + 1 >= interval[0]) {
                res.getLast()[1] = Math.max(res.getLast()[1], interval[1]);
            }
            else{
                res.add(interval);
            }
        }
        
        return res;
    }
    
    
    
}
