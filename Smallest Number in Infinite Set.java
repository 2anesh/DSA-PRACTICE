class SmallestInfiniteSet {
    Set<Integer> setofDeleted;
    int smallest;
    public SmallestInfiniteSet(){
        setofDeleted = new HashSet<>();
        smallest =1;
    }

      
    public int popSmallest() {
        if(!setofDeleted.contains(smallest)){
            setofDeleted.add(smallest);
            return smallest++;
        }else{
            while(setofDeleted.contains(smallest)){
                smallest++;
            }
            setofDeleted.add(smallest);
            return smallest;
        }
    }
    
    public void addBack(int num) {
        if(smallest>num){
            smallest = num;
        }
        setofDeleted.remove(num);
    }
}
