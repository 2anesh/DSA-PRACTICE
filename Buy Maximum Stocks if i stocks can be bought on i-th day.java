class Solution {
    public static int buyMaximumProducts(int n, int k, int[] price) {
           PriorityQueue<Value> priorityQueue=new PriorityQueue<Value>();
        for(int i=0;i<n;i++)
        {
            priorityQueue.add(new Value(price[i],i+1));
        }
        int count=0;
        while (k>0&&!priorityQueue.isEmpty())
        {
            Value temp=priorityQueue.poll();

            int day=temp.index;

            int value=temp.value;

             while (day>0&&k>=value)
             {
                       k-=value;

                     count++;

                      day--;
             }
        }
        return count;
    }
}
 class Value implements Comparable<Value>
{
    int value,index;
    public Value(int value, int index) {

        this.value = value;

        this.index = index;
    }
    @Override
    public int compareTo(Value o) {
        return Integer.compare(this.value,o.value);
    }
}
