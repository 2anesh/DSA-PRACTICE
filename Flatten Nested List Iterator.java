public class NestedIterator implements Iterator<Integer> {
    List<Integer> list;
    Iterator<Integer> iterator;
   
    public NestedIterator(List<NestedInteger> nestedList) {
        list = new ArrayList<>();
        getNumber(nestedList);
        iterator = list.iterator();
    }

    @Override
    public Integer next() {
        return iterator.next();
    }

    @Override
    public boolean hasNext() {
        return iterator.hasNext(); 
    }
    
    public void getNumber(List<NestedInteger> nestedList){
        
        Iterator<NestedInteger> iterator = nestedList.iterator(); ;

        while(iterator.hasNext()){
            NestedInteger val = iterator.next();
            
            if(val.isInteger()){
                list.add(val.getInteger());
            }else{
                getNumber(val.getList());
            }
        }
        
    }
}
